#include "model/OfflineMsgModel.hpp"
#include "Database.h"


//向offlinemessage表插入userId和msg
void OfflineMsgModel::insert(int userId,std::string msg)
{
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "insert into offlinemessage values(%d, '%s')", userId, msg.c_str());

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

//根据userId删除offlinemessage表对应的数据
void OfflineMsgModel::remove(int userId)
{
    // 组织sql语句
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "delete from offlinemessage where userid=%d", userId);

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}


//根据userId查询offlinemessage表对应的数据
std::vector<std::string> OfflineMsgModel::query(int userId)
{
    // 组织sql语句
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "select message from offlinemessage where userid = %d", userId);

    std::vector<std::string> vec;
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            // 把userid用户的所有消息放入vec中返回
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                vec.push_back(row[0]);
            }
        }
        mysql_free_result(res);   
        printf("offlineMsgModel query finished");
        return vec;
    }
    printf("offlineMsgModel query finished");
    return vec;
}
