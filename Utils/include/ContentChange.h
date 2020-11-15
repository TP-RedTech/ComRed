#ifndef UTILS_INCLUDE_CONTENTCHANGE_H_
#define UTILS_INCLUDE_CONTENTCHANGE_H_

#include <iostream>

#include "BaseChange.h"

class ContentChange: public BaseChange {
 private:
  std::string content;

 public:
  ContentChange();
  ContentChange(std::string str);

  std::string getContent();

 void applyChanges() override;
};

#endif //UTILS_INCLUDE_CONTENTCHANGE_H_
