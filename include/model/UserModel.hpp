#ifndef USER_MODEL_H
#define USER_MODEL_H

#include "User.hpp"

class UserModel
{
public:
    //向User表插入user，因为userId是自增的，它也会自动设定user ID
    bool insert(User &user);
    
    //根据用户id查询user的id name password state信息
    User query(int id);

    //通过user的状态和id创建sql语句更新对应user的状态
    bool updateState(User user);

    //重置，将所有online状态的用户，设置成offline
    void resetState();

};



#endif