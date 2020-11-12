#ifndef UTILS_INCLUDE_INDEXCHANGE_H_
#define UTILS_INCLUDE_INDEXCHANGE_H_

#include <iostream>

#include "BaseChange.h"

class IndexChange: public BaseChange {
 private:
  int index;

 public:
  IndexChange();

  int getIndex();

  TypeChange type() override;
};

#endif //UTILS_INCLUDE_INDEXCHANGE_H_
