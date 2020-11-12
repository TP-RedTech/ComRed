#ifndef COMREDSERVER_REQUEST_H
#define COMREDSERVER_REQUEST_H

#include <string>
#include <vector>
#include "Header.h"

namespace http::server {
struct Request {
  std::string method;
  std::string uri;
  int http_version_major;
  int http_version_minor;
  std::vector<header> headers;
};
}

#endif //COMREDSERVER_REQUEST_H
