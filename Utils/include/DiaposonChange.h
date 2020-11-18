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
  DiaposonChange(int start, int end);

  Diaposon getDiaposon();

  void applyChanges() override;
};

#endif //UTILS_INCLUDE_DIAPOSONCHANGE_H_
