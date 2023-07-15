#include "model/GroupModel.hpp"
#include "Database.h"

//创建一个group表，并设定的自动增长groupId
bool GroupModel::createGroup(Group &group)
{
    // insert into allgroup(groupname, groupdesc) values('chat-server', 'test for create group2');
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "insert into allgroup(groupname, groupdesc) values('%s', '%s')",
        group.getName().c_str(), group.getDesc().c_str());
    
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            group.setId(mysql_insert_id(mysql.get_connection()));
            return true;
        }
    }

    return false;
}

// 加入群组（用户ID 加入群组ID 在群组角色）
void GroupModel::addGroup(int userid, int groupid, std::string role)
{
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "insert into groupuser values(%d, %d, '%s')",
        groupid, userid, role.c_str());
    
    MySQL mysql;
    if (mysql.connect())
    {
        mysql.update(sql);
    }
}

//返回含有userid的所有群组的所有成员的信息  Group有个成员groupuser
//1. 先根据userid在groupuser表中查询出该用户所属的群组信息
//2. 再根据群组信息，查询属于该群组的所有用户的userid，并且和user表进行多表联合查询，查出群组中所有用户的详细信息保存在vector中并返回
std::vector<Group> GroupModel::queryGroups(int userid)
{
    char sql[1024] = {0};
    snprintf(sql, sizeof(sql), "select a.id,a.groupname,a.groupdesc from allgroup a inner join \
        groupuser b on a.id = b.groupid where b.userid=%d",userid);
    
    std::vector<Group> groupVec;

    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            // 查出userid所有的群组信息存放进groupVec
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                Group group;
                group.setId(atoi(row[0]));
                group.setName(row[1]);
                group.setDesc(row[2]);
                groupVec.push_back(group);
            }
            mysql_free_result(res);
        }
    }

    // 查询群组的用户信息
    for (Group &group : groupVec)
    {
        snprintf(sql, sizeof(sql), "select a.id,a.name,a.state,b.grouprole from user a \
            inner join groupuser b on b.userid = a.id where b.groupid=%d",
                group.getId());

        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                GroupUser user;
                user.setId(atoi(row[0]));
                user.setName(row[1]);
                user.setState(row[2]);
                user.setRole(row[3]);
                group.getUsers().push_back(user);
            }
            mysql_free_result(res);
        }
    }
    return groupVec;
}

// 根据指定的groupid查询群组用户id列表，除userid自己，用于群聊业务给群组其它成员群发消息
std::vector<int> GroupModel::queryGroupUsers(int userid, int groupid)
{
    char sql[1024] = {0};
    sprintf(sql, "select userid from groupuser where groupid = %d and userid != %d", groupid, userid);

    vector<int> idVec;
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr)
        {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr)
            {
                idVec.push_back(atoi(row[0]));
            }
            mysql_free_result(res);
        }
    }
    return idVec;  
}