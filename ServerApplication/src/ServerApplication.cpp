#include "ServerApplication.h"

int ServerApplication::createDocument(std::string userData, std::string documentName) {
    return 0;
}

std::vector<std::string> ServerApplication::updateDocument(std::string userData, int docId, std::vector<std::string> operations) {
    return std::vector<std::string>();
}

void ServerApplication::deleteDocument(std::string userData, int docId) {

}

std::string ServerApplication::readDocument(std::string userData, int docId) {
    return std::string();
}

std::string ServerApplication::connectDocument(std::string userData, int docId) {
    for (int i = 0; i < sessions->size(); i++) {
        if (sessions->at(i)->getIdDocument() == docId) {
            // TODO: Change id edtior
            // Some id editor
            int edtiorId = i * docId;
            sessions->at(i)->addEditor(edtiorId);
            return std::string();
        }
    }

    // If no such session has been created
    // TODO: Get document with this id from db
    std::shared_ptr<Document> document(new Document(docId, "some text"));
    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));

    this->addSession(session);

    return std::string();
}

std::string ServerApplication::loginUser(std::string userData) {
    return std::string();
}

std::string ServerApplication::registerUser(std::string userData) {
    return std::string();
}

std::string ServerApplication::logoutUser(std::string userData) {
    return std::string();
}

std::string ServerApplication::updateUser(std::string userData, std::string newUserData) {
    return std::string();
}

void ServerApplication::addSession(std::shared_ptr<Session> session) {
    sessions->push_back(std::move(session));
}