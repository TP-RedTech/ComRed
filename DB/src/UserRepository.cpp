#include "../inc/UserRepository.h"

UserRepository::UserRepository(weak_ptr<AbstractDBController> ctrl) {}
    
UserRepository::~UserRepository() {}

void UserRepository::createUser(User& u) {}

User UserRepository::getById(int id) {}
