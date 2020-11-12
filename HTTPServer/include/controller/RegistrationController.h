#ifndef COMREDSERVER_REGISTRATIONCONTROLLER_H
#define COMREDSERVER_REGISTRATIONCONTROLLER_H

#include "BaseController.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class RegistrationController : public BaseController {
public:
  RegistrationController();
  virtual Reply handleRequest(const Request &request) = 0;
};
}

#endif
