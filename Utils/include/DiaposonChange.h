#ifndef UTILS_INCLUDE_DIAPOSONCHANGE_H_
#define UTILS_INCLUDE_DIAPOSONCHANGE_H_

#include <iostream>

#include "BaseChange.h"
#include "Diaposon.h"

class DiaposonChange: public BaseChange {
 private:
  Diaposon diaposon;

 public:
  DiaposonChange();

  Diaposon getDiaposon();

  TypeChange type() override;
};

#endif //UTILS_INCLUDE_DIAPOSONCHANGE_H_
