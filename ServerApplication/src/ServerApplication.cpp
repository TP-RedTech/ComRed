#include "ServerApplication.h"

std::pair<ApplicationErrors, std::string> ServerApplication::createDocument(int editorId, std::string documentName) {
    return std::make_pair(ApplicationErrors::success, "Good");
}

std::pair<ApplicationErrors, std::string> ServerApplication::updateDocument(int editorId, int docId, int cursorPosition, std::string operations) {
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO:- From std::string to Operation
            std::shared_ptr<Operation> operation = std::shared_ptr<Operation>(new Operation());
            operation->setIdEditor(editorId);
            operation->makeOpFromString(operations);
            (*i)->manageOperation(editorId, operation);
        }
    }
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::deleteDocument(int editorId, int docId) {
    //
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Delete session with this docId
            i = sessions.erase(i);
        }
    }

    // TODO: Delete this document from DB
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::readDocument(std::string userData, int docId) {
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::connectDocument(int editorId, int docId) {
    for (auto i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Change id edtior
            // Some id editor
            (*i)->addEditor(editorId);
            return std::make_pair(ApplicationErrors::success, "Success");
        }
    }

    // If no such session has been created
    // TODO: Get document with this id from db
    std::shared_ptr<Document> document(new Document(docId, ""));
    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));
    session->addEditor(editorId);
    this->addSession(session);

    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::loginUser(std::string userData) {
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::registerUser(std::string userData) {
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::logoutUser(std::string userData){
    return std::make_pair(ApplicationErrors::success, "Success");
}

std::pair<ApplicationErrors, std::string> ServerApplication::updateUser(std::string userData, std::string newUserData) {
    return std::make_pair(ApplicationErrors::success, "Success");
}

void ServerApplication::addSession(std::shared_ptr<Session> session) {
    sessions.push_back(std::move(session));
}
