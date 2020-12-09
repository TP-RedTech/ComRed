#ifndef COMREDSERVER_REGISTRATIONCONTROLLER_H
#define COMREDSERVER_REGISTRATIONCONTROLLER_H

#include "Controller.h"

namespace server {
class RegistrationController : public Controller {
public:
  RegistrationController() = default;
  Reply handleRequest(Request request) override;
};
}

#endif
