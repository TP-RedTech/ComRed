#ifndef COMREDSERVER_LOGINCONTROLLER_H
#define COMREDSERVER_LOGINCONTROLLER_H

#include "Controller.h"

namespace server {
class LoginController : public Controller {
public:
  LoginController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif
