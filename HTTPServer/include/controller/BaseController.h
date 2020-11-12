#ifndef COMREDSERVER_BASECONTROLLER_H
#define COMREDSERVER_BASECONTROLLER_H

#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class BaseController {
public:
  BaseController();
  virtual Reply handleRequest(const Request &request) = 0;
};
}

#endif //COMREDSERVER_BASECONTROLLER_H
