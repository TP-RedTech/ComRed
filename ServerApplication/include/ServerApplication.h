#ifndef UNTITLED_SERVERAPPLICATION_H
#define UNTITLED_SERVERAPPLICATION_H

#include "ServerHeader.h"
#include "Session.h"
#include "DocumentManager.h"
#include "UserManager.h"

class BaseServerApplication {
public:
    BaseServerApplication() = default;
    virtual ~BaseServerApplication() = default;
    virtual int createDocument() = 0;
    virtual std::vector<Operation> updateDocument(Operation operation) = 0;
    virtual void deleteDocument() = 0;
    virtual void readDocument() = 0;
    virtual std::string connectDocument(int idUser, int idDocument) = 0;
    virtual std::string loginUser() = 0;
    virtual std::string registerUser(std::string data) = 0;
    virtual std::string logoutUser() = 0;
    virtual std::string updateUser() = 0;
};

class ServerApplication: public BaseServerApplication {
public:
    ServerApplication() = default;
    int createDocument() override;
    std::vector<Operation> updateDocument(Operation operation) override;
    void deleteDocument() override;
    void readDocument() override;
    std::string connectDocument(int idUser, int idDocument) override;
    std::string loginUser() override;
    std::string registerUser(std::string data) override;
    std::string logoutUser() override;
    std::string updateUser() override;

private:
    std::unique_ptr<std::vector<Session>> sessions;
    std::unique_ptr<DocumentManager> documentManager;
    std::unique_ptr<UserManager> userManager;
};


#endif //UNTITLED_SERVERAPPLICATION_H
