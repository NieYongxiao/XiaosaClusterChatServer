#ifndef OFFLINE_MSG_MODEL
#define OFFLINE_MSG_MODEL

#include <string>
#include <vector>
using std::string,std::vector;

class OfflineMsgModel
{
public:
    //向offlinemessage表插入userId和msg
    void insert(int userId,string msg);

    //根据userId删除offlinemessage表对应的数据
    void remove(int userId);

    //根据userId查询offlinemessage表对应的数据
    vector<string> query(int userId);
};



#endif