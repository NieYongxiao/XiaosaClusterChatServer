#ifndef CHAT_SERVICE_H
#define CHAT_SERVICE_H

#include <muduo/net/TcpConnection.h>
#include <unordered_map>
#include <functional>
#include <mutex>
#include "../third_party/json/json.hpp"
#include "model/UserModel.hpp"
#include "model/OfflineMsgModel.hpp"
#include "model/FriendModel.hpp"
#include "model/GroupModel.hpp"
#include "Redis.hpp"

using json = nlohmann::json;
using namespace muduo;
using namespace muduo::net;



//回调函数类型
using MsgHandler = std::function<void(const TcpConnectionPtr &,json &,Timestamp)>;

//TcpConnectionPtr是指向TcpConnection对象的智能指针，一个TcpConnection代表一个TCP连接，它封装了底层的网络操作，提供了与连接相关的功能和接口。

//muduo::net::TcpConnection::send(const muduo::StringPiece &message)用于向 TCP 连接发送数据。
//该函数将提供的数据通过TCP连接发送给对方。它使用底层的操作系统网络套接字发送数据，将message参数表示的内容按照指定的协议规则（如 TCP/IP）发送到连接的对端。


//聊天服务器业务类
class ChatService
{  
public:
    // ChatService 单例模式
    // thread safe
    static ChatService* instance() {
        static ChatService service;
        return &service;
    }

    // 登录业务
    void loginHandler(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 注册业务
    void registerHandler(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 一对一聊天业务
    void oneChatHandler(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 添加好友业务
    void addFriendHandler(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 获取对应消息的处理器
    MsgHandler getHandler(int msgId);
    // 创建群组业务
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 加入群组业务
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 群组聊天业务
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 处理客户端异常退出
    void clientCloseExceptionHandler(const TcpConnectionPtr &conn);
    // 服务端异常终止之后的操作
    void reset();
    //redis订阅消息触发的回调函数
    void redis_subscribe_message_handler(int channel, string message);
private:
    ChatService();
    ChatService(const ChatService &) = delete;
    ChatService& operator=(const ChatService&) = delete;
private:
    //存储消息id和其对应的业务处理方法
    std::unordered_map<int ,MsgHandler> _msgHandlerMap;

    //存储在线用户的通信连接 int是用户id
    std::unordered_map<int,TcpConnectionPtr> _userConnMap;

    //定义互斥锁
    std::mutex _connMutex;

    //redis操作对象
    Redis _redis;

    //数据操作类对象
    UserModel _userModel;
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;
};


#endif