#include <gtest/gtest.h>
#include "gmock/gmock.h"

using ::testing::AtLeast;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgReferee;

#include "../inc/AbstractDBController.h"
#include "../inc/DocumentRepository.h"
#include "../inc/UserRepository.h"

class MockDBController : public AbstractDBController
{
public:
    MOCK_METHOD2(runQuery, bool(const string&, vector<vector<string>>&));
};

class TestDBController : public ::testing::Test
{
protected: 
    void SetUp()
    {
        db_ctrl = make_shared<MockDBController>();
    }

    void TearDown() {}

    shared_ptr<MockDBController> db_ctrl;
    vector<vector<string>> result;
};

TEST_F(TestDBController, workWithDocument)
{
    EXPECT_CALL(*db_ctrl, runQuery("", result)).Times(AtLeast(5));
    DocumentRepository drep(db_ctrl);
    Document doc;
    User user;
    drep.createDoc(doc);
    drep.changeDoc(doc);
    drep.getById(doc.getId());
    drep.addUser(user, doc);
    drep.getByUser(user);
}

TEST_F(TestDBController, workWithUser)
{
    EXPECT_CALL(*db_ctrl, runQuery("", result)).Times(AtLeast(2));
    UserRepository urep(db_ctrl);
    User user;
    urep.createUser(user);
    urep.getById(user.getId());
}


// TO_DO: перенести в другой файл
/*
class MockUserRepository : public UserRepositoryI
{
public:
    explicit MockUserRepository(weak_ptr<AbstractDBController> db) : 
        UserRepositoryI(db) {}

    MOCK_METHOD1(createTest, void(User&));
    MOCK_METHOD1(getTest, User(int));
};

TEST(UserRepository, methodsCall)
{
    shared_ptr<DBController> db_ctrl = make_shared<DBController>();
    MockUserRepository murep(db_ctrl);
    UserManager manager(murep);
    User user;
    EXPECT_CALL(murep, createTest(user)).Times(AtLeast(1));
    EXPECT_CALL(murep, getTest(user.getId())).Times(AtLeast(1));
    manager.create("");
    managet.getById(user.getId());
}

*/