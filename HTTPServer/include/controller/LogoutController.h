#ifndef COMREDSERVER_LOGOUTCONTROLLER_H
#define COMREDSERVER_LOGOUTCONTROLLER_H

#include "BaseController.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class LogoutController : public BaseController {
public:
  LogoutController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
