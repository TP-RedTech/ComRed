#ifndef __USERREPOSITORY_H__
#define __USERREPOSITORY_H__

#include <boost/format.hpp>
#include <memory>
#include "AbstractDBController.h"
#include "../../Utils/include/User.h"

using namespace std;

class UserRepositoryI
{
public:
    UserRepositoryI() = default;
    virtual ~UserRepositoryI() = default;
    virtual void createTest(User& u) = 0;
    virtual void updateTest(User& u) = 0;
    virtual User getTest(int id) = 0;
};

class UserRepository : public UserRepositoryI
{
public:
    UserRepository(weak_ptr<AbstractDBController> ctrl);
    ~UserRepository();

    void createUser(User& u);
    void updateUser(User& u);
    User getById(int id);

    virtual void createTest(User& u) { createUser(u); }
    virtual void updateTest(User& u) { updateUser(u); }
    virtual User getTest(int id) { return getById(id); }

private:
    weak_ptr<AbstractDBController> db;
};

#endif