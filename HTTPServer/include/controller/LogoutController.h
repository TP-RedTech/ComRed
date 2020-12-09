#ifndef COMREDSERVER_LOGOUTCONTROLLER_H
#define COMREDSERVER_LOGOUTCONTROLLER_H

#include "Controller.h"

namespace server {
class LogoutController : public Controller {
public:
  LogoutController() = default;
  Reply handleRequest(Request request) override;
};
}

#endif