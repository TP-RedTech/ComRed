#ifndef UNTITLED_SERVERAPPLICATION_H
#define UNTITLED_SERVERAPPLICATION_H

#include "ServerHeader.h"
#include "Session.h"
#include "../../DB/include/DocumentRepository.h"
#include "../../DB/include/UserRepository.h"

class BaseServerApplication {
public:
    BaseServerApplication() = default;
    virtual ~BaseServerApplication() { }
    virtual int createDocument(std::string userData, std::string documentName) = 0;
    virtual void updateDocument(int editorId, int docId, std::string operations) = 0;
    virtual void deleteDocument(std::string userData, int docId) = 0;
    virtual std::string readDocument(std::string userData, int docId) = 0;
    virtual std::string connectDocument(int editorId, int docId) = 0;
    virtual std::string loginUser(std::string userData) = 0;
    virtual std::string registerUser(std::string userData) = 0;
    virtual std::string logoutUser(std::string userData) = 0;
    virtual std::string updateUser(std::string userData, std::string newUserData) = 0;

};

class ServerApplication: public BaseServerApplication {
public:
    ServerApplication() {
        sessions = std::vector<std::shared_ptr<Session>>();
    }

    virtual ~ServerApplication() {
    }

    int createDocument(std::string userData, std::string documentName) override;
    void updateDocument(int editorId, int docId, std::string operations) override;
    void deleteDocument(std::string userData, int docId) override;
    std::string readDocument(std::string userData, int docId) override;
    std::string connectDocument(int editorId, int docId) override;
    std::string loginUser(std::string userData) override;
    std::string registerUser(std::string userData) override;
    std::string logoutUser(std::string userData) override;
    std::string updateUser(std::string userData, std::string newUserData) override;

private:
    std::vector<std::shared_ptr<Session>> sessions;

    void addSession(std::shared_ptr<Session> session);
};


#endif //UNTITLED_SERVERAPPLICATION_H
