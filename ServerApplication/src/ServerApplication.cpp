#include "ServerApplication.h"

int ServerApplication::createDocument(std::string userData, std::string documentName) {
    return 0;
}

std::vector<std::string> ServerApplication::updateDocument(int editorId, int docId, std::vector<std::string> operations) {
    return std::vector<std::string>();
}

void ServerApplication::deleteDocument(std::string userData, int docId){
    //
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Delete session with this docId
            i = sessions.erase(i);
//            std::cout << "[action] Sessions with id = " << docId << " has been deleted" << std::endl;
        }
    }

    // TODO: Delete this document from DB
}

std::string ServerApplication::readDocument(std::string userData, int docId) {
    return std::string();
}

std::string ServerApplication::connectDocument(int editorId, int docId) {
    std::cout << sessions.empty() << " << " << std::endl;
    for (auto i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Change id edtior
            // Some id editor
            (*i)->addEditor(editorId);
            std::cout << "[action] Edtior with id = " << editorId << " has been added" << std::endl;
            return std::string();
        }
    }

    // If no such session has been created
    // TODO: Get document with this id from db
    std::shared_ptr<Document> document(new Document(docId, "some text"));
    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));
    session->addEditor(editorId);
    this->addSession(session);
    std::cout << "[action] Session with id = " << document->getId() << " has been created" << std::endl;

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
