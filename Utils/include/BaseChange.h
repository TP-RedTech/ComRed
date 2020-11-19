#ifndef UTILS_INCLUDE_BASECHANGE_H_
#define UTILS_INCLUDE_BASECHANGE_H_

class BaseChange{
 public:
  BaseChange() = default;
  virtual void applyChanges() = 0;
  virtual ~BaseChange() = default;

};

#endif //UTILS_INCLUDE_BASECHANGE_H_
