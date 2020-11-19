#ifndef COMREDSERVER_LOGINCONTROLLER_H
#define COMREDSERVER_LOGINCONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http { namespace server {
class LoginController : public Controller {
public:
  LoginController();
  Reply handleRequest(const Request &request) override;
};
} }

#endif
