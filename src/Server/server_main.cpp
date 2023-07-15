#include "ChatServer.hpp"
#include "ChatService.hpp"
#include <muduo/base/Logging.h>
#include <iostream>
#include <signal.h>
using namespace std;

void resetHandler(int )
{
    LOG_INFO <<"capture the SIGINT, will reset state\n";
    ChatService::instance()->reset();
    exit(0);
}

int main(int argc,char **argv)
{

    signal(SIGINT,resetHandler);

    EventLoop loop;

    //ip和port初始化addr
    InetAddress addr("127.0.0.1",atoi(argv[1]));
    //初始化类内的Tcperver 和 EventLoop 并绑定连接等事件的相关回调函数
    ChatServer server(&loop,addr,"ChatServer");

    //启动服务器的运行，创建监听套接字、绑定地址、监听连接等操作，然后程序进入一个无限循环中，不断监听事件并进行处理。
    server.start();
    loop.loop();

    return 0;
}