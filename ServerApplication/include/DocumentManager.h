#ifndef UNTITLED_DOCUMENTMANAGER_H
#define UNTITLED_DOCUMENTMANAGER_H

#include "ServerHeader.h"

class BaseDocumentManager {
public:
    BaseDocumentManager() = default;
    virtual ~BaseDocumentManager() = default;
    virtual void addUser(int idUser, int idDocument) = 0;
    virtual int createDocument() = 0;
    virtual std::string deleteDocument() = 0;
    virtual Document getByIdUser(int idUser) = 0;
    virtual Document getByIdDocument(int idDocument) = 0;
};

class DocumentManager: public BaseDocumentManager {
public:
    DocumentManager() = default;
    void addUser(int idUser, int idDocument) override;
    int createDocument() override;
    std::string deleteDocument() override;
    Document getByIdUser(int idUser) override;
    Document getByIdDocument(int idDocument) override;
};

#endif //UNTITLED_DOCUMENTMANAGER_H
