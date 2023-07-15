#include "model/UserModel.hpp"
#include "Database.h"
#include <iostream>

//向User表插入user，因为userId是自增的，它也会自动设定user ID
bool UserModel::insert(User& user)
{
    char sql[1024]={0};

    snprintf(sql, sizeof(sql), "insert into user(name, password, state) values('%s', '%s', '%s')",
        user.getName().c_str(), user.getPassword().c_str(), user.getState().c_str());
    
    MySQL mysql;
    if(mysql.connect())
    {
        if(mysql.update(sql))
        {
            //mysql_insert_id()用于获取上一次插入操作后生成的自增主键值，该函数返回最后一个插入语句所生成的AUTO_INCREMENT值。
            user.setId(mysql_insert_id(mysql.get_connection()));
            return true;
        }
    }
    return false;
}

//根据用户id查询user的id name password state信息
User UserModel::query(int id)
{
    char sql[1024] = {0};
    snprintf(sql,sizeof(sql),"select * from user where id = %d",id);

    MySQL mysql;
    if(mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if(res!=nullptr)
        {
            //mysql_fetch_row()用于从查询结果集中获取一行数据，返回一个MYSQL_ROW结构，表示查询结果中的一行数据。
            MYSQL_ROW row = mysql_fetch_row(res);
            if(row!=nullptr)
            {
                // 找到了该user就生成一个User对象，填入信息后返回
                User user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setPassword(row[2]);
                user.setState(row[3]);
                mysql_free_result(res);
                return user;
            }
        }
    }
    //返回空User
    return User();
}

//通过user的状态和id创建sql语句更新对应user的状态
bool UserModel::updateState(User user)
{
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "update user set state = '%s' where id =%d", user.getState().c_str(), user.getId());
    printf("snprintf success\n");
    
    MySQL mysql;
    if (mysql.connect())
    {
        printf("UserModel connect sql success\n");
        if (mysql.update(sql))
        {        
            printf("UserModel update state success and return true\n");
            return true;
        }        
        printf("UserModel update state success\n");

    }
    else printf("mysql.connect() failed\n");
    return false;
}

// 将所有online状态的用户，设置成offline
void UserModel::resetState()
{
    // 1.组装sql语句
    char sql[1024] = "update user set state = 'offline' where state = 'online'";

    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
    else cerr<<"mysql connect failed"<<endl;
}