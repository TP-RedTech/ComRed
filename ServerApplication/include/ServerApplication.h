#ifndef UNTITLED_SERVERAPPLICATION_H
#define UNTITLED_SERVERAPPLICATION_H

#include "ServerHeader.h"
#include "Session.h"
#include "../../DB/include/DocumentRepository.h"
#include "../../DB/include/UserRepository.h"

class BaseServerApplication {
public:
    BaseServerApplication() = default;
    virtual ~BaseServerApplication() = default;
    virtual int createDocument(std::string userData, std::string documentName) = 0;
    virtual std::vector<std::string> updateDocument(std::string userData, int docId, std::vector<std::string> operations) = 0;
    virtual void deleteDocument(std::string userData, int docId) = 0;
    virtual std::string readDocument(std::string userData, int docId) = 0;
    virtual std::string connectDocument(std::string userData, int docId) = 0;
    virtual std::string loginUser(std::string userData) = 0;
    virtual std::string registerUser(std::string userData) = 0;
    virtual std::string logoutUser(std::string userData) = 0;
    virtual std::string updateUser(std::string userData, std::string newUserData) = 0;
};

class ServerApplication: public BaseServerApplication {
public:
    ServerApplication() = default;
    ~ServerApplication() override;
    int createDocument(std::string userData, std::string documentName) override;
    std::vector<std::string> updateDocument(std::string userData, int docId, std::vector<std::string> operations) override;
    void deleteDocument(std::string userData, int docId) override;
    std::string readDocument(std::string userData, int docId) override;
    std::string connectDocument(std::string userData, int docId) override;
    std::string loginUser(std::string userData) override;
    std::string registerUser(std::string userData) override;
    std::string logoutUser(std::string userData) override;
    std::string updateUser(std::string userData, std::string newUserData) override;

private:
    std::unique_ptr<std::vector<Session>> sessions;
    std::shared_ptr<DocumentRepositoryI> documentManager;
    std::shared_ptr<UserRepository> userManager;
};


#endif //UNTITLED_SERVERAPPLICATION_H
