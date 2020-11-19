#ifndef COMREDSERVER_REQUEST_H
#define COMREDSERVER_REQUEST_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Header.h"

namespace http {
struct Request {
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  Headers headers;
};
}

#endif //COMREDSERVER_REQUEST_H
