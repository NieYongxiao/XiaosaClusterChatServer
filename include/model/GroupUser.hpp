#ifndef _GROUP_USER_H
#define _GROUP_USER_H

#include <string>

class GroupUser
{
public:
    GroupUser(int id = -1, std::string name = "", 
        std::string pwd = "", std::string state = "offline")
        : _id(id),
          _name(name),
          _state(state)
    {}
public:
    void setId(const int &id) { _id = id; }
    void setName(const std::string &name) { _name = name; }
    void setPassword(const std::string &paw) { _password = paw; }
    void setState(const std::string &state) { _state = state; }
    void setRole(const std::string &role) { _role = role;}
public:
    int getId() { return _id; }
    std::string getName() { return _name; } 
    std::string getPassword() { return _password; } 
    std::string getState() { return _state; } 
    std::string getRole() { return _role; }
protected:
    int _id;
    std::string _name;
    std::string _password;
    std::string _state;    
    std::string _role;
};


#endif