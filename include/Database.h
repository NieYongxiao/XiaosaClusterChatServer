#ifndef DB_H
#define DB_H

#include <mysql/mysql.h>
#include <string>
using namespace std;

class MySQL
{
public:
    MySQL();
    ~MySQL();
    //封装了mysql_real_connect
    bool connect();

    //封装了mysql_query，返回是否成功
    bool update(string sql);

    //也是封装了mysql_query，只不过返回query的结果，保存在MYSQL_RES*中
    MYSQL_RES* query(string sql);
    
    //返回MySQL类的 m_conn
    MYSQL* get_connection();
private:
    MYSQL *m_conn;
};


#endif