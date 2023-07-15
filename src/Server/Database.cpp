#include "Database.h"
#include <muduo/base/Logging.h>
#include <iostream>

static const string server = "127.0.0.1";
static const string user = "root";
static const string password = "123456";
static const string dbname = "chat";


MySQL::MySQL()
{
    this->m_conn = mysql_init(nullptr);
}

MySQL::~MySQL()
{
    if(this->m_conn != nullptr)
        mysql_close(this->m_conn);
}

bool MySQL::connect()
{
    printf("mysql real connect started\n");
    MYSQL *p = mysql_real_connect(m_conn,server.c_str(),user.c_str(),
                                  password.c_str(),dbname.c_str(),3306,nullptr,0);
    if(p != nullptr){
        printf("mysql connect success\n");
        mysql_query(m_conn,"set names gbk");
    }
    //muduo库中有日志的记录宏
    else 
    {        
        printf("mysql connect failed\n");
        LOG_INFO << "connect mysql failed!";
    }

    return p;
}

//就是mysql_query
bool MySQL::update(string sql)
{
    //查询成功 返回0  否则返回1 
    if(!mysql_query(m_conn,sql.c_str()))
    {
        printf("Mysql update successfully");
        LOG_INFO << __FILE__ << ":" << __LINE__ <<" :"<<sql <<" 查询成功！";
        return false;
    }
    
    else
    {        
        printf("Mysql update failed");
        LOG_INFO << __FILE__ << ":" << __LINE__ <<" :" <<sql <<" 查询失败！";
    }
    return true;
}


MYSQL_RES* MySQL::query(string sql)
{
    if(mysql_query(m_conn,sql.c_str()))
    {
        LOG_INFO << __FILE__ << ":" << __LINE__ <<" :"
                <<sql <<" 查询失败！";
        return nullptr;
    }
    //对于每个可以产生一个结果集的命令（比如select、show等等），发起mysql_query，mysql_use_result语句初始化一个取回结果集
    return mysql_use_result(m_conn);
}

MYSQL* MySQL::get_connection()
{
    return m_conn;
}
