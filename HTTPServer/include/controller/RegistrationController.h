#ifndef COMREDSERVER_REGISTRATIONCONTROLLER_H
#define COMREDSERVER_REGISTRATIONCONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class RegistrationController : public Controller {
public:
  RegistrationController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
