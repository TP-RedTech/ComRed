#ifndef UTILS_INCLUDE_OPERATION_H_
#define UTILS_INCLUDE_OPERATION_H_

#include <iostream>
#include <vector>

#include "BaseChange.h"

class Operation{
 private:
  int revision;
  int idEditor;
  size_t lengthBeforeOperation;
  size_t lengthAfterOperation;
  std::vector<BaseChange> changes;

 public:
  Operation();

  void setRevision(int newRevision);

  int getRevision() const;

  void setIdEditor(int newId);

  int getIdEditor() const;

  void setLengthBeforeOperation(size_t newLength);

  void setLengthAfterOperation(size_t newLength);

  size_t getLengthBeforeOperation() const;

  size_t getLengthAfterOperation() const;

  size_t getSizeOfChanges() const;

  void addChange(BaseChange newChange);

  Operation mergeOperations(Operation anotherOperation);

};

#endif //UTILS_INCLUDE_OPERATION_H_
