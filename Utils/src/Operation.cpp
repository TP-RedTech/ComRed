#include "Operation.h"

Operation::Operation() {

}

void Operation::setRevision(int newRevision) {

}

int Operation::getRevision() const {
  return int();
}

void Operation::setIdEditor(int newId) {

}

int Operation::getIdEditor() const {
  return int();
}

void Operation::setLengthBeforeOperation(size_t newLength) {

}

void Operation::setLengthAfterOperation(size_t newLength) {

}

size_t Operation::getLengthBeforeOperation() const {
  return size_t();
}

size_t Operation::getLengthAfterOperation() const {
  return size_t();
}

size_t Operation::getSizeOfChanges() const {
  return size_t();
}

void Operation::addChange(BaseChange newChange) {

}

Operation Operation::mergeOperations(Operation anotherOperation) {
  return Operation();
}

