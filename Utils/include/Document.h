#ifndef UTILS_INCLUDE_DOCUMENT_H_
#define UTILS_INCLUDE_DOCUMENT_H_

#include <iostream>
#include <vector>

#include "BaseChange.h"
#include "Operation.h"

class Document{
 private:
  int id;
  std::string password;
  std::vector<int> ownersId;
  std::string text;

 public:
  Document();

  int getId() const;

  std::string getText();

  void addOwner(int ownerId);

  void updateText(std::vector<Operation> operation);

  void setId(int newId);
};

#endif //UTILS_INCLUDE_DOCUMENT_H_