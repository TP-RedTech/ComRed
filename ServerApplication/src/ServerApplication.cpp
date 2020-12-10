#include "ServerApplication.h"

int ServerApplication::createDocument(std::string userData, std::string documentName) {
    return 0;
}

void ServerApplication::updateDocument(int editorId, int docId, std::string operations) {
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO:- From std::string to Operation
            std::shared_ptr<Operation> operation = std::shared_ptr<Operation>(new Operation());
            operation->setIdEditor(editorId);
            operation->makeOpFromString(operations);
            (*i)->manageOperation(editorId, operation);
        }
    }
}

void ServerApplication::deleteDocument(std::string userData, int docId){
    //
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Delete session with this docId
            i = sessions.erase(i);
        }
    }

    // TODO: Delete this document from DB
}

std::string ServerApplication::readDocument(std::string userData, int docId) {
    return std::string();
}

std::string ServerApplication::connectDocument(int editorId, int docId) {
    for (auto i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Change id edtior
            // Some id editor
            (*i)->addEditor(editorId);
            return std::string();
        }
    }

    // If no such session has been created
    // TODO: Get document with this id from db
    std::shared_ptr<Document> document(new Document(docId, ""));
    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));
    session->addEditor(editorId);
    this->addSession(session);

    return std::string();
}

std::string ServerApplication::loginUser(std::string userData) {
    return std::string();
}

std::string ServerApplication::registerUser(std::string userData) {
    return std::string();
}

std::string ServerApplication::logoutUser(std::string userData){
    return std::string();
}

std::string ServerApplication::updateUser(std::string userData, std::string newUserData) {
    return std::string();
}

void ServerApplication::addSession(std::shared_ptr<Session> session) {
    sessions.push_back(std::move(session));
}
