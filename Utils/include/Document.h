#ifndef UTILS_INCLUDE_DOCUMENT_H_
#define UTILS_INCLUDE_DOCUMENT_H_

#include <iostream>
#include <vector>
#include <string>

#include "BaseChange.h"
#include "Operation.h"

class Document{
 private:
  int id;
  std::string password;
  std::vector<int> ownersId;
  std::string text;

 public:
  Document(int idDocument,
           const std::string& textDocument): id(idDocument),
           password(std::string()),
           ownersId(0),
           text{textDocument} { };

  Document(int idDocument, std::string&& textDocument):
           id(idDocument),
           password(std::string()),
           ownersId(0),
           text{std::move(textDocument)} { };

  ~Document() = default;

  int getId() const;

  std::string getText();

  void addOwner(int ownerId);

  void updateText(Operation operation);

  void setId(int newId);
};

#endif //UTILS_INCLUDE_DOCUMENT_H_
