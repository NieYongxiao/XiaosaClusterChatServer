#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;

//基于muduo库开发服务器类
class ChatServer
{
public:
    //初始化聊天服务器对象
    ChatServer(EventLoop* loop,const InetAddress& listenAddr,const std::string &nameArg);

    //TcpServer.start();
    void start();


private:
    //连接相关信息的回调函数，新连接到来，旧连接断开
    void onConnection(const TcpConnectionPtr &);

    //读写事件相关信息的回调函数
    void onMessage(const TcpConnectionPtr &,Buffer*,Timestamp);

    TcpServer _server;
    EventLoop* _loop;
};

//TcpServer类封装了底层的网络操作，提供了简单而高效的接口，提供了以下功能：
//监听指定的端口，接受客户端的连接请求。
//在有新连接建立时，自动创建一个 TcpConnection 对象，并绑定相应的回调函数。
//管理所有的 TcpConnection 对象，包括连接的建立、断开等。
//提供多线程支持，可以为每个连接创建一个独立的 EventLoop 线程。


//Event Loop负责处理事件的分发和调度。事件可以是网络连接的建立、数据的到达、定时器的触发等。
//Event Loop 采用非阻塞的方式监听事件，当有事件发生时，它会调用相应的回调函数进行处理。
//Event Loop是事件循环的核心，并提供了一系列的成员函数，用于注册事件、添加定时器、执行回调函数等操作。

//muduo::Timestamp是表示时间戳的类。封装了时间戳值，提供了对时间的表示和比较的功能。类的实现基于底层的时间函数，可以精确到微秒级别。
//muduo::net::Buffer是缓冲区类，封装了一个内部的字符数组（缓冲区），具有自动扩展和管理的功能，用于在网络通信中进行数据的存储和传输。

#endif