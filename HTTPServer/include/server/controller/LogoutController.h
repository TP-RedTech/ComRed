#ifndef COMREDSERVER_LOGOUTCONTROLLER_H
#define COMREDSERVER_LOGOUTCONTROLLER_H

#include "Controller.h"

namespace server {
class LogoutController : public Controller {
public:
  LogoutController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif