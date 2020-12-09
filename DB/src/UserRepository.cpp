#include "../include/UserRepository.h"

UserRepository::UserRepository(weak_ptr<AbstractDBController> ctrl) :
    db(ctrl) {}
    
UserRepository::~UserRepository() {}

void UserRepository::createUser(User& u) 
{
    vector<vector<string>> query_result = {};
    string query1 =
        (boost::format(
            "INSERT INTO user VALUES(%1%, '%2%', '%3');") 
            % "default" 
            % u.getName()
            % u.getPassword()
        ).str();
    string query2 = 
        (boost::format(
            "SELECT max(id) FROM user;")
        ).str();
    if (auto ctrl = db.lock()) 
    {
        if (ctrl->runQuery(query1, query_result) != true)
            throw runtime_error("cannot create user.");
        if (ctrl->runQuery(query2, query_result) != true)
            throw runtime_error("cannot get id of user.");
        u.setId(stoi(query_result[0][0]));
    } 
    else
        throw runtime_error("no db controller.");
}

User UserRepository::getById(int id) 
{
    vector<vector<string>> query_result = {};
    string query =
        (boost::format(
            "SELECT * FROM user WHERE id = %1%;") 
            % id
        ).str();
    if (auto ctrl = db.lock()) 
    {
        if (ctrl->runQuery(query, query_result) != true)
            throw runtime_error("cannot get user.");
    } 
    else
        throw runtime_error("no db controller.");
    return User(stoi(query_result[0][0]), query_result[0][1], query_result[0][2]); 
}

void UserRepository::updateUser(User& u) 
{
    vector<vector<string>> query_result = {};
    string query =
        (boost::format(
            "UPDATE user SET name = '%1%', password = '%2%' WHERE id = %3%;") 
            % u.getName()
            % u.getPassword()
            % u.getId()
        ).str();
    if (auto ctrl = db.lock()) 
    {
        if (ctrl->runQuery(query, query_result) != true)
            throw runtime_error("cannot update document.");
    } 
    else
        throw runtime_error("no db controller.");
}
