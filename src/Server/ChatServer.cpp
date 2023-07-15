#include "ChatServer.hpp"
#include "ChatService.hpp"
#include "../third_party/json/json.hpp"
#include <iostream>
#include <functional>
#include <string>
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

//std::placeholders::_1是C++ 标准库中的一个占位符，它用于表示一个参数的位置
//std::bind是C++11引入的一个函数模板，用于将函数对象绑定到一组参数上，以创建一个新的可调用对象。在绑定过程中，可以使用占位符来表示参数的位置，这样在实际调用时，可以将具体的参数值传入。
//std::placeholders::_1 表示第一个参数的位置。如果绑定了多个参数，可以使用 _2、_3…依次表示第二个、第三个参数的位置，以此类推。


ChatServer::ChatServer(EventLoop *loop,
                        const InetAddress& listenAddr,
                        const string &nameArg)
    :_server(loop,listenAddr,nameArg),_loop(loop)
{
    //绑定当出现连接事件的回调函数、
    this->_server.setConnectionCallback(bind(&ChatServer::onConnection,this,_1));

    //绑定TcpServer接收到消息时的回调函数
    //void setMessageCallback(const MessageCallback& cb);
    //其中，MessageCallback是一个函数类型，表示消息的回调函数，它的定义如下：
    // typedef std::function<void (const TcpConnectionPtr&,
    //                              Buffer*,
    //                              Timestamp)> MessageCallback;
    this->_server.setMessageCallback(bind(&ChatServer::onMessage,this,_1,_2,_3));

    //设置subLoop线程数量
    this->_server.setThreadNum(4);
}

//_server.start();
void ChatServer::start()
{
    cerr<<"Server has started"<<endl;
    _server.start();
}

void ChatServer::onConnection(const TcpConnectionPtr &conn)
{
    if(!conn->connected())
    {
        ChatService::instance()->clientCloseExceptionHandler(conn);
        conn->shutdown();
    }
}

void ChatServer::onMessage(const TcpConnectionPtr& conn,
                            Buffer* buffer,
                            Timestamp time)
{
    //Buffer是接收客户端发来消息的缓冲区，此函数将缓冲区中的值全部取出并以字符串的形式返回
    string buf = buffer->retrieveAllAsString();

    //数据反序列化
    json js = json::parse(buf);

    //完全解耦网络模块和业务模块，不要在网络模块中调用业务模块的方法
    //通过js["meg_id"]来获取不同的业务处理器，即事先绑定的回调方法
    //js["msgid"].get<int> 将js["msgid"]对应的值强制转换成int
    auto msgHandler = ChatService::instance()->getHandler(js["msgid"].get<int>());

    //回调消息绑定好的事件处理器，来执行相应的业务处理
    msgHandler(conn,js,time);
}