#ifndef FRIEND_MODEL_H
#define FRIEND_MODEL_H

#include "User.hpp"
#include <vector>

class FriendModel
{
public:
    //向friend表插入userId和friendId
    void insert(int userId,int friendId);

    //返回用户好友列表
    std::vector<User> query(int userId);
};


#endif