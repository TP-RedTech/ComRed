#ifndef UTILS_INCLUDE_OPERATION_H_
#define UTILS_INCLUDE_OPERATION_H_

#include <iostream>
#include <vector>
#include "Change.h"

class Operation {
 private:
  size_t lenBeforeOperation;
  size_t lenAfterOperation;
  std::vector<Change> ops;

 public:

  size_t getLenBeforeOperation() const;

  size_t getLenAfterOperation() const;

  void setLenBeforeOperation(const size_t& len);

  void setLenAfterOperation(const size_t& len);

  void addOperation(const Change& change);

  std::vector<Change> getChanges() const;

  Operation();

  // skip characters
  void retain(int newNumber);

  // insert a new string at the current position
  void insert(const std::string& newString);

  void erase(int newNumber);

  bool isNoEffect() const;

  std::string applyToString(const std::string& anotherString) const;

  Operation compose (const Operation& operation2);

  std::vector<Operation> transform(const Operation& secondOp);
};

#endif //UTILS_INCLUDE_OPERATION_H_