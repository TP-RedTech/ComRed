#ifndef COMREDSERVER_LOGOUTCONTROLLER_H
#define COMREDSERVER_LOGOUTCONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class LogoutController : public Controller {
public:
  LogoutController();
  Reply handleRequest(const Request &request) override;
};
}

#endif