#include "ServerApplication.h"

std::pair<ApplicationErrors, std::string> ServerApplication::createDocument(int editorId, std::string documentName) {
    Document doc;
    try {
        docRepository->createDoc(doc);
    } catch(const std::exception& error) {
        std::cout << error.what() << std::endl;
        return std::make_pair(ApplicationErrors::failure, "Error with creating document");;
    };

    std::cout << "Document was successfully created with id " + std::to_string(doc.getId()) << std::endl;
    return std::make_pair(ApplicationErrors::success, "Document was successfully created with id " + std::to_string(doc.getId()));
}

std::pair<ApplicationErrors, std::string> ServerApplication::updateDocument(int editorId, int docId, int cursorPosition, std::string operations) {
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO:- From std::string to Operation
            std::shared_ptr<Operation> operation = std::shared_ptr<Operation>(new Operation());
            operation->setIdEditor(editorId);
            operation->makeOpFromString(operations);
            (*i)->manageOperation(editorId, operation);
            return std::make_pair(ApplicationErrors::success, "Change sent successfully");
        }
    }
    return std::make_pair(ApplicationErrors::failure, "Document is not open");
}

std::pair<ApplicationErrors, std::string> ServerApplication::deleteDocument(int editorId, int docId) {
    for (std::vector<std::shared_ptr<Session>>::const_iterator i = sessions.cbegin(); i != sessions.cend(); i++) {
        if ((*i)->getIdDocument() == docId) {
            // TODO: Delete document with this Id
            i = sessions.erase(i);
            return std::make_pair(ApplicationErrors::success, "Document was successfully deleted");
        }
    }
    return std::make_pair(ApplicationErrors::failure, "This document does not exist");
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
            return std::make_pair(ApplicationErrors::success, (*i)->getDocumentText());
        }
    }

    // If no such session has been created
    // TODO: Get document with this id from db
    std::shared_ptr<Document> document;
    try {
        std::cout << docRepository->getById(docId).getId() << " " << docRepository->getById(docId).getText() << std::endl;
        document = std::make_shared<Document>(docRepository->getById(docId));
    } catch(const std::exception& error) {
        std::cout << "Document was not created" << std::endl;
        return std::make_pair(ApplicationErrors::failure, "Document was not created");;
    };
    std::shared_ptr<EditorManager> editorManager(new EditorManager(document));
    std::shared_ptr<Session> session(new Session(document->getId(), editorManager));
    session->addEditor(editorId);
    this->addSession(session);
    return std::make_pair(ApplicationErrors::success, session->getDocumentText());
}

std::pair<ApplicationErrors, std::string> ServerApplication::loginUser(std::string userData) {
    return std::make_pair(ApplicationErrors::success, "User was successfully logined");
}

std::pair<ApplicationErrors, std::string> ServerApplication::registerUser(std::string userData) {
    return std::make_pair(ApplicationErrors::success, "User was successfully registred");
}

std::pair<ApplicationErrors, std::string> ServerApplication::logoutUser(std::string userData){
    return std::make_pair(ApplicationErrors::success, "User was successfully logouted");
}

std::pair<ApplicationErrors, std::string> ServerApplication::updateUser(std::string userData, std::string newUserData) {
    return std::make_pair(ApplicationErrors::success, "User was successfully updated");
}

void ServerApplication::addSession(std::shared_ptr<Session> session) {
    sessions.push_back(std::move(session));
}

std::shared_ptr<ServerApplication> ServerApplication::instance;
