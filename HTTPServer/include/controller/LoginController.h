#ifndef COMREDSERVER_LOGINCONTROLLER_H
#define COMREDSERVER_LOGINCONTROLLER_H

#include "BaseController.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class LoginController : public BaseController {
public:
  LoginController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
