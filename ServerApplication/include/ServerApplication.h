#ifndef UNTITLED_SERVERAPPLICATION_H
#define UNTITLED_SERVERAPPLICATION_H

#include "ServerHeader.h"
#include "Session.h"
#include "../../DB/include/DocumentRepository.h"
#include "../../DB/include/UserRepository.h"

enum class ApplicationErrors {
    failure,
    success,
};

class BaseServerApplication {
public:
    BaseServerApplication() = default;
    virtual ~BaseServerApplication() { }
    virtual std::pair<ApplicationErrors, std::string> createDocument(int editorId, std::string documentName) = 0;
    virtual std::pair<ApplicationErrors, std::string> updateDocument(int editorId, int docId, int cursorPosition, std::string operations) = 0;
    virtual std::pair<ApplicationErrors, std::string> deleteDocument(int editorId, int docId) = 0;
    virtual std::pair<ApplicationErrors, std::string> readDocument(std::string userData, int docId) = 0;
    virtual std::pair<ApplicationErrors, std::string> connectDocument(int editorId, int docId) = 0;
    virtual std::pair<ApplicationErrors, std::string> loginUser(std::string userData) = 0;
    virtual std::pair<ApplicationErrors, std::string> registerUser(std::string userData) = 0;
    virtual std::pair<ApplicationErrors, std::string> logoutUser(std::string userData) = 0;
    virtual std::pair<ApplicationErrors, std::string> updateUser(std::string userData, std::string newUserData) = 0;

};

class ServerApplication: public BaseServerApplication {
protected:
    ServerApplication(): sessions(0) { }
    ServerApplication(const ServerApplication&);
    ServerApplication& operator=(ServerApplication&);

public:
    static std::shared_ptr<ServerApplication> get_instance() {
        if (instance == nullptr) {
            instance =  std::shared_ptr<ServerApplication>(new ServerApplication) ;
        }
        return instance;
    }

    std::pair<ApplicationErrors, std::string> createDocument(int editorId, std::string documentName) override;
    std::pair<ApplicationErrors, std::string> updateDocument(int editorId, int docId, int cursorPosition, std::string operations) override;
    std::pair<ApplicationErrors, std::string> deleteDocument(int editorId, int docId) override;
    std::pair<ApplicationErrors, std::string> readDocument(std::string userData, int docId) override;
    std::pair<ApplicationErrors, std::string> connectDocument(int editorId, int docId) override;
    std::pair<ApplicationErrors, std::string> loginUser(std::string userData) override;
    std::pair<ApplicationErrors, std::string> registerUser(std::string userData) override;
    std::pair<ApplicationErrors, std::string> logoutUser(std::string userData) override;
    std::pair<ApplicationErrors, std::string> updateUser(std::string userData, std::string newUserData) override;

private:
    static std::shared_ptr<ServerApplication> instance;
    std::vector<std::shared_ptr<Session>> sessions;

    void addSession(std::shared_ptr<Session> session);
};


#endif //UNTITLED_SERVERAPPLICATION_H
