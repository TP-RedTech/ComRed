#include "ServerApplication.h"

ServerApplication::~ServerApplication() {

}

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
