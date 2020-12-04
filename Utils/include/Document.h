#ifndef UTILS_INCLUDE_DOCUMENT_H_
#define UTILS_INCLUDE_DOCUMENT_H_

#include <iostream>
#include <vector>
#include <string>

#include "BaseChange.h"
#include "Operation.h"

class Document{
public:
    Document() {}
    Document(int idDocument,
             const std::string& textDocument): id(idDocument),
                                               password(std::string()),
                                               text{textDocument} {
        std::cout << "Document" << id << " manager has been constructed" << std::endl;
    };

    Document(int idDocument, std::string&& textDocument):
            id(idDocument),
            password(std::string()),
            text{std::move(textDocument)} {
        std::cout << "Document" << id << " manager has been constructed" << std::endl;
    };

    Document(const Document &document): id(document.id), password(document.password), text(document.text)
    {
        std::cout << "Document" << id << " manager has been constructed" << std::endl;

    }

    Document(std::shared_ptr<Document> document): id(document->id), password(document->password), text(document->text)
    {
        std::cout << "Document" << id << " manager has been constructed" << std::endl;

    }

    ~Document() {
        std::cout << "Document" << id << " manager has been destructed" << std::endl;
    }

    int getId() const;

    std::string getText();

    void updateText(Operation operation);

    void setId(int newId);

private:
    int id;
    std::string text;
    std::string password;

};

#endif //UTILS_INCLUDE_DOCUMENT_H_