#ifndef UTILS_INCLUDE_BASECHANGE_H_
#define UTILS_INCLUDE_BASECHANGE_H_

class BaseChange{
 public:
  enum TypeChange {
    DIAPOSON,
    INDEX,
    CONTENT,
  };
 private:
  TypeChange typeChange;

 public:
  BaseChange(TypeChange typeChange);

  virtual TypeChange type() = 0;

};

#endif //UTILS_INCLUDE_BASECHANGE_H_
