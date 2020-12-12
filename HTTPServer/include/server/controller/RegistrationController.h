#ifndef COMREDSERVER_REGISTRATIONCONTROLLER_H
#define COMREDSERVER_REGISTRATIONCONTROLLER_H

#include "Controller.h"

namespace server {
class RegistrationController : public Controller {
public:
  RegistrationController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif
