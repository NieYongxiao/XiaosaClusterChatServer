#include "FriendModel.hpp"
#include "Database.h"

//向friend表插入userId和friendId
void FriendModel::insert(int userId,int friendId)
{
    //组织sql语句
    char sql[1024] = {0};
    snprintf(sql,sizeof(sql),"insert into friend values(%d,%d)",userId,friendId);

    MySQL mysql;
    if(mysql.connect())
    {
        mysql.update(sql);
    }
}

//返回用户好友列表
std::vector<User> FriendModel::query(int userId)
{
    char sql[1024] ={0};

    //带有内连接（INNER JOIN）的SELECT语句，别名a引用user表 b引用friend表 之间满足条件的记录。
    sprintf(sql,"select a.id,a.name,a.state from user a inner join friend b on b.friendid = a.id where b.userid = %d",userId);

    std::vector<User> vec;
    MySQL mysql;
    if(mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if(res != nullptr)
        {
            //MYSQL_ROW是MySQL提供的一种数据结构，表示查询结果的一行数据。实际上是一个指向char*数组的指针，每个元素都是一个字符串，对应查询结果中的一个字段值。
            MYSQL_ROW row;
            while((row = mysql_fetch_row(res)) != nullptr)
            {
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                vec.push_back(user);
            }           
            mysql_free_result(res);
        }
    }
    return vec;
}