#ifndef UTILS_INCLUDE_CONTENTCHANGE_H_
#define UTILS_INCLUDE_CONTENTCHANGE_H_

#include <iostream>

#include "BaseChange.h"

class ContentChange: public BaseChange {
 private:
  std::string content;

 public:
  ContentChange();

  std::string getContent();

  TypeChange type() override;
};

#endif //UTILS_INCLUDE_CONTENTCHANGE_H_
