#ifndef COMREDSERVER_BASECONTROLLER_H
#define COMREDSERVER_BASECONTROLLER_H

#include "requests/Request.h"
#include "requests/Reply.h"

namespace http { namespace server {
class Controller {
public:
  Controller();
  virtual Reply handleRequest(const Request &request) = 0;
};
} }

#endif //COMREDSERVER_BASECONTROLLER_H
