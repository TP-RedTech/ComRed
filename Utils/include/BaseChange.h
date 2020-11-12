#ifndef UTILS_INCLUDE_BASECHANGE_H_
#define UTILS_INCLUDE_BASECHANGE_H_

class BaseChange{
  enum TypeChange {
    DIAPOSON,
    INDEX,
    CONTENT,
  };

 private:
  TypeChange typeChange;

 public:
  BaseChange(TypeChange typeChange);

  TypeChange type();

};

#endif //UTILS_INCLUDE_BASECHANGE_H_
