#include "ChatService.hpp"
#include "public.cpp"
#include <muduo/base/Logging.h>
#include <string>
#include <vector>
using namespace muduo;
using namespace std;

//因为记录用户连接情况的表是可能被多个线程操作的，所以访问表的操作都要使用互斥锁进行保护。

ChatService::ChatService()
{
    //注册各类消息处理函数
    this->_msgHandlerMap.insert({LOGIN_MSG,bind(&ChatService::loginHandler,this,_1,_2,_3)});
    this->_msgHandlerMap.insert({REGISTER_MSG,bind(&ChatService::registerHandler,this,_1,_2,_3)});
    this->_msgHandlerMap.insert({ONE_CHAT_MSG,bind(&ChatService::oneChatHandler,this,_1,_2,_3)});
    this->_msgHandlerMap.insert({ADD_FRIEND_MSG,bind(&ChatService::addFriendHandler,this,_1,_2,_3)});

    //注册群组业务管理相关事件处理函数
    this->_msgHandlerMap.insert({CREATE_GROUP_MSG,bind(&ChatService::createGroup,this,_1,_2,_3)});
    this->_msgHandlerMap.insert({ADD_GROUP_MSG,bind(&ChatService::addGroup,this,_1,_2,_3)});
    this->_msgHandlerMap.insert({GROUP_CHAT_MSG,bind(&ChatService::groupChat,this,_1,_2,_3)});

    // redis初始化,并绑定消息处理函数
    if(_redis.connect())
    {
        _redis.init_notify_handler(std::bind(&ChatService::redis_subscribe_message_handler,this,_1,_2));
    }
}

//redis收到消息时触发的回调函数
//通过redis作为中间件，解耦多服务器，从不同的channel中进行查找
void ChatService::redis_subscribe_message_handler(int channel,string message)
{   
    //锁 防止用户状态发生变化
    lock_guard<mutex> lock(_connMutex);
    
    //在线
    //_userConnMap.insert({id,conn}); 因此channel就是id
    auto it = _userConnMap.find(channel);
    if(it != _userConnMap.end())
    {
        it->second->send(message);
        return ;
    }

    //转储离线
    _offlineMsgModel.insert(channel,message);
}

MsgHandler ChatService::getHandler(int msgId)
{
    auto it = _msgHandlerMap.find(msgId);
    //没有找到对应的处理函数
    if(it == _msgHandlerMap.end())
    {
        //=表示值捕获，&表示引用捕获
        return [=](const TcpConnectionPtr conn,json js,Timestamp ts){
            LOG_ERROR<<"msgId: "<<msgId<<" can not find handler";
        };
    }
    return _msgHandlerMap[msgId];
}

// 服务器异常，业务重置方法  在此处是对服务器进程输入ctrl+c强行中止进程
void ChatService::reset()
{    
    // 将所有online状态的用户，设置成offline
    _userModel.resetState();
}

// 处理客户端异常退出
void ChatService::clientCloseExceptionHandler(const TcpConnectionPtr &conn)
{
    User user;

    {
        lock_guard<mutex> lock(this->_connMutex);
        for(auto it =_userConnMap.begin();it!=_userConnMap.end();++it)
        {
            if(it->second == conn)
            {
                //从map表里删除用户连接信息
                user.setId(it->first);
                _userConnMap.erase(it);
                break;
            }
        }
    }

    //redis用户注销
    _redis.unsubscribe(user.getId());

    //更新用户状态信息
    if(user.getId() != 1)
    {
        user.setState("offline");
        _userModel.updateState(user);
    }
}

//一对一聊天服务
void ChatService::oneChatHandler(const TcpConnectionPtr &conn,json &js,Timestamp time)
{
    int toId = js["toid"].get<int>();

    {
        lock_guard<mutex> lock(_connMutex);
        // 接收信息的用户ID
        auto it = _userConnMap.find(toId);
        //确认是在线状态
        if(it != _userConnMap.end())
        {
            //直接用tcp发送消息
            it->second->send(js.dump());
            return;
        }
    }

    // 用户如果在其他主机，publish消息到redis
    // 在连接表里没找到 但是在数据库里找到并发现其状态在线 说明在其他主机
    User user = _userModel.query(toId);
    if(user.getState() == "online")
    {
        // redis publish
        _redis.publish(toId,js.dump());

        return;
    }
    //toID 不在线则存储离线消息
    _offlineMsgModel.insert(toId, js.dump());
}

//添加朋友
void ChatService::addFriendHandler(const TcpConnectionPtr& conn,json &js,Timestamp time)
{
    int userId = js["id"].get<int>();
    int friendId = js["friendId"].get<int>();

    _friendModel.insert(userId, friendId);
}

//创建群组业务
void ChatService::createGroup(const TcpConnectionPtr& conn,json &js,Timestamp time)
{
    int userId = js["id"].get<int>();
    string name = js["groupname"];
    string desc = js["groupdesc"];

    Group group(-1,name,desc);
    if(_groupModel.createGroup(group))
    {
        //存储群组创建人信息
        _groupModel.addGroup(userId,group.getId(),"creator");
    }
}


//加入群组业务
void ChatService::addGroup(const TcpConnectionPtr& conn,json &js,Timestamp time)
{
    int userId = js["id"].get<int>();
    int groupId = js["groupid"].get<int>();
    _groupModel.addGroup(userId, groupId, "normal");
}

//群组聊天业务
void ChatService::groupChat(const TcpConnectionPtr& conn,json& js,Timestamp time)
{
    int userId = js["id"].get<int>();
    int groupId = js["groupid"].get<int>();
    std::vector<int> userIdVec = _groupModel.queryGroupUsers(userId, groupId);

    //TODO 发消息时要锁，不然有可能发送到一半被别的线程夺走了
    lock_guard<mutex> lock(_connMutex);
    for (int id : userIdVec)
    {
        auto it = _userConnMap.find(id);
        //在同一主机
        if (it != _userConnMap.end())
        {
            // 转发群消息
            it->second->send(js.dump());
        }
        else
        {
            // 查询toid是否在线
            User user = _userModel.query(id);
            if (user.getState() == "online")
            {
                // redis向群组成员publish信息
                _redis.publish(id, js.dump());
            }
            else
            {
                //转储离线消息
                _offlineMsgModel.insert(id, js.dump());
            }
        }
    }
}


//登陆业务
//从json中得到用户id，用户密码，并与数据库中的值进行对比，还要判断是否重复登陆
//登陆成功后会得到离线的消息以及好友的信息
// {"msgid":1,"id":13,"password":"123456"}
// {"errmsg":"this account is using, input another!","errno":2,"msgid":2}
void ChatService::loginHandler(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    LOG_DEBUG << "do login service!";
    printf("login service\n");
    int id = js["id"].get<int>();
    string password = js["password"];

    User user = _userModel.query(id);
    if(user.getId() == id && user.getPassword() == password)
    {
        if( user.getState() == "online")
        {
            // 该用户已经登录，不能重复登录
            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 2;
            response["errmsg"] = "this account is using, input another!";
            
            conn->send(response.dump());
        }
        else
        {
            printf("准备登陆\n");
            // 登录成功，记录用户连接信息
            // 需要考虑线程安全问题 onMessage会在不同线程中被调用
            {
                lock_guard<mutex> lock(_connMutex);
                _userConnMap.insert({id,conn});
            }
            printf("redis准备登陆\n");
            //TODO id用户登录成功后，向redis订阅channel(id) 一个id对应一个channel
            _redis.subscribe(id); 
            printf("redis登陆success\n");

            // 登录成功，更新用户状态信息 state offline => online
            user.setState("online");
            printf("set state success\n");
            _userModel.updateState(user);
            
            printf("update user success\n");

            json response;
            response["msgid"] = LOGIN_MSG_ACK;
            response["errno"] = 0;
            response["id"] = user.getId();
            response["name"] = user.getName();

            // 查询该用户是否有离线消息
            vector<string> vec = _offlineMsgModel.query(id);
            if (!vec.empty())
            {
                response["offlinemsg"] = vec;
                // 读取该用户的离线消息后，将该用户离线消息删除掉
                _offlineMsgModel.remove(id);
            }
            else
            {
                LOG_INFO << "无离线消息";
            }            
            printf("check offline msg success\n");


            std::vector<User> userVec = _friendModel.query(id);
            if (!userVec.empty())
            {
                std::vector<std::string> vec;
                for (auto& user : userVec)
                {
                    json js;
                    js["id"] = user.getId();
                    js["name"] = user.getName();
                    js["state"] = user.getState();
                    vec.push_back(js.dump());
                }
                response["friends"] = vec;
            }
            printf("find friend success\n");

            conn->send(response.dump());            
            printf("send success\n");

        }
    }
    printf("login successful\n");
}


//注册业务
void ChatService::registerHandler(const TcpConnectionPtr &conn, json &js, Timestamp time)
{
    LOG_DEBUG <<"do register service! ";
    string name = js["name"];
    string password = js["password"];

    User user;
    user.setName(name);
    user.setPassword(password);

    bool state = _userModel.insert(user);
    //注册成功
    if(state)
    {
        json response;
        response["msgid"] = REGISTER_MSG_ACK;
        response["errno"] = 0;
        response["id"] = user.getId();
        
        // json::dump() 将序列化信息转换为std::string
        conn->send(response.dump());
    }
    else
    {
        json response;
        response["msgid"] = REGISTER_MSG_ACK;
        response["errno"] = 1;
        //注册失败，不用返回id
        conn->send(response.dump());
    }
}