#ifndef _GROUP_MODEL_H
#define _GROUP_MODEL_H

#include "Group.hpp"
#include <string>
#include <vector>

class GroupModel
{
public:
    //创建一个group表，并设定的自动增长groupId
    bool createGroup(Group& group);

    // 加入群组（用户ID 加入群组ID 在群组角色）
    void addGroup(int userId,int groupId,std::string role);

    //查询用户所在群组信息
    std::vector<Group> queryGroups(int userId);

    //根据指定的groupid查询群组用户id列表，除userid自己，用于群聊业务给群组其它成员群发消息
    std::vector<int> queryGroupUsers(int userId,int groupId);
};


#endif