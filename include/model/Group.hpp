#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "GroupUser.hpp"

class Group
{
public:
    //desc description 表示描述符
    Group(int id=-1,std::string name="",std::string desc ="")
         : _id(id), _name(name), _desc(desc)
    {}
public:
    void setId(int id) {_id = id;} 
    void setName(std::string name) {_name = name;}
    void setDesc(std::string desc) {_desc = desc;}
public:
    int getId() {return _id;}
    std::string getName() {return _name;}
    std::string getDesc() {return _desc;}
    std::vector<GroupUser> getUsers() {return _users;}    
private:
    int _id;
    std::string _name;
    std::string _desc;
    std::vector<GroupUser> _users;
};


#endif