#ifndef COMREDSERVER_LOGINCONTROLLER_H
#define COMREDSERVER_LOGINCONTROLLER_H

#include "Controller.h"

namespace server {
class LoginController : public Controller {
public:
  LoginController() = default;
  Reply handleRequest(Request request) override;
};
}

#endif
