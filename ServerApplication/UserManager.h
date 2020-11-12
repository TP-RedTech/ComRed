#ifndef UNTITLED_USERMANAGER_H
#define UNTITLED_USERMANAGER_H

#include "string"
#include "undefStructs.h"

class BaseUserManager {
public:
    virtual ~BaseUserManager() = default;
    virtual std::string create(std::string data) = 0;
    virtual std::string getById(int id) = 0;
};

class UserManager: public BaseUserManager {
public:
    UserManager() = default;
    std::string create(std::string data) override {};
    std::string getById(int id) override {};
};

#endif //UNTITLED_USERMANAGER_H
