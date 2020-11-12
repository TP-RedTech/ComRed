#ifndef __USERREPOSITORY_H__
#define __USERREPOSITORY_H__

#include <memory>
#include "DBController.h"
//#include "User.h"

using namespace std;

class UserRepository
{
public:
    UserRepository(weak_ptr<AbstractDBController> ctrl);
    ~UserRepository();

    void createUser(User& u);
    User getById(int id);

private:
    weak_ptr<AbstractDBController> db;
};

#endif