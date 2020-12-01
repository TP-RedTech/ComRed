#ifndef UTILS_INCLUDE_DOCUMENT_H_
#define UTILS_INCLUDE_DOCUMENT_H_

#include <iostream>
#include <vector>
#include <string>

#include "BaseChange.h"
#include "Operation.h"

class Document{
public:
    Document() = default;
    Document(int idDocument,
             const std::string& textDocument): id(idDocument),
                                               password(std::string()),
                                               text{textDocument} { };

    Document(int idDocument, std::string&& textDocument):
            id(idDocument),
            password(std::string()),
            text{std::move(textDocument)} { };

    Document(const Document &document): id(document.id), password(document.password), text(document.text)
    // Примечание: Мы имеем прямой доступ к членам объекта drob, поскольку мы сейчас находимся внутри класса Drob
    {
        std::cout << "New document via constructer created\n";
        std::cout << "id = " << this->id << std::endl;
        std::cout << "text = " << this->text << std::endl;

    }

    ~Document() = default;

    int getId() const;

    std::string getText();

    void updateText(Operation operation);

    void setId(int newId);

private:
    int id;
    std::string password;
    std::string text;
};

#endif //UTILS_INCLUDE_DOCUMENT_H_