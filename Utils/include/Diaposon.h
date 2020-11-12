#ifndef UTILS_INCLUDE_DIAPOSON_H_
#define UTILS_INCLUDE_DIAPOSON_H_

#include <iostream>

class Diaposon {
 private:
  size_t startPos;
  size_t endPos;

 public:
  Diaposon();

  Diaposon(size_t start, size_t end);

  size_t getStartPos();

  size_t getEndPos();
};

#endif //UTILS_INCLUDE_DIAPOSON_H_
