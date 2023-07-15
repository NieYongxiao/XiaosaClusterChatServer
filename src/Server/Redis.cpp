#include "Redis.hpp"
#include <iostream>

using namespace std;

Redis::Redis():publish_context(nullptr),subscribe_context(nullptr)
{    
}

Redis::~Redis()
{
    if(publish_context != nullptr)
    {
        //断开连接并且释放redisContext
        redisFree(publish_context);
    } 
    if(subscribe_context != nullptr)
    {
        redisFree(subscribe_context);
    }
}

bool Redis::connect()
{
    //该函数用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。
    publish_context = redisConnect("127.0.0.1",6379);
    if(publish_context == nullptr)
    {
        //cout：写到标准输出的ostream对象,经过缓冲后输出，默认情况下是显示器，是标准输出
        //cerr：输出到标准错误的ostream对象，不经过缓冲而直接输出，一般用于迅速输出出错信息，默认情况下被关联到标准输出流，但它不被缓冲，也就说错误消息可以直接发送到显示器
        cerr << "connect redis failed" << endl;
        return false;
    }

    subscribe_context = redisConnect("127.0.0.1",6379);
    if(subscribe_context == nullptr)
    {
        cerr << "connect redis failed" <<endl;
        return false;
    }

    //独立线程 接收订阅通道的消息
    thread t([&]()
    {
        observer_channel_message();    
    });
    t.detach();

    cout<<"connect redis-server seccess!"<<endl;
    return true;
}

//向Redis指定的通道channel发布消息
bool Redis::publish(int channel,string message)
{
    // 相当于publish 键 值
    // redis 127.0.0.1:6379> PUBLISH runoobChat "Redis PUBLISH test"
    // 该函数执行命令，就如sql数据库中的SQL语句一样，只是执行的是redis数据库中的操作命令，
    redisReply *reply = (redisReply*)redisCommand(publish_context,"PUBLISH %d %s",channel,message);
    if(reply == nullptr)
    {
        cerr<<"publish command failed" <<endl;
        return false;
    }
    //释放资源
    freeReplyObject(reply);
    return true;
}

// 向Redis指定的通道subscribe订阅消息
bool Redis::subscribe(int channel)
{
    //redisAppendCommand用于将Redis命令追加到客户端的输出缓冲区（output buffer）中，而不会立即发送到服务器，也不会等待服务器的响应
    if(redisAppendCommand(subscribe_context,"SUBSCRIBE %d",channel) == REDIS_ERR)
    {
        cerr << "subscribe command failed" <<endl;
        return false;
    }

    int done = 0;
    while(!done)
    {
        //redisBufferWrite将客户端输出缓冲区中的数据写入到Redis服务器。它会将输出缓冲区中的内容发送到服务器，并等待完成写入操作。
        //并且redisBufferWrite函数是一个非阻塞操作，它将客户端输出缓冲区中的数据写入到Redis服务器，但并不保证立即完成写入。当done的值为0时，表示写入操作尚未完成，需要继续等待。
        if(redisBufferWrite(subscribe_context,&done) == REDIS_ERR)
        {
            cerr << "subscribe command failed" <<endl;
            return false;
        }
    }
    // redisCommand 会先把命令缓存到context中，然后调用RedisAppendCommand发送给redis
    // redis执行subscribe是阻塞，不会响应，不会给我们一个reply
    // redis 127.0.0.1:6379> SUBSCRIBE runoobChat
    return true;
}

//取消对通道channel的订阅
bool Redis::unsubscribe(int channel)
{
    if(REDIS_ERR == redisAppendCommand(subscribe_context,"UNSUBSCRIBE %d",channel))
    {
        cerr << "subscibe command failed" <<endl;
        return false;
    }

    int done = 0;
    while(!done)
    {
        if(REDIS_ERR == redisBufferWrite(subscribe_context,&done))
        {
            cerr <<"subscribe command failed"<<endl;
            return false;
        }
    }
    return true;
}

//独立线程中接收订阅通道的信息
void Redis::observer_channel_message()
{
    redisReply* reply = nullptr;    

    //redisGetReply函数是一个用于从Redis服务器接收响应的函数，用于与Redis服务器进行通信并获取执行命令的结果
    while(REDIS_OK == redisGetReply(subscribe_context,(void **)&reply))
    {
        //reply里面是返回的数据有三个：0.message，1.通道号，2.消息
        if(reply != nullptr && reply->element[2] != nullptr && reply->element[2]->str != nullptr)
        {
            //在ChatService中无参初始化中用redis_subscribe_message_handler函数初始化了notify_message_handler函数
            notify_message_handler(atoi(reply->element[1]->str),reply->element[2]->str);
        }
        freeReplyObject(reply);
    }
    cerr << "----------------------- observer_channel_message quit--------------------------" << endl;
}

void Redis::init_notify_handler(redis_handler handler)
{
    notify_message_handler = handler;
}