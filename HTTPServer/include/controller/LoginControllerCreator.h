#ifndef COMREDSERVER_INCLUDE_CONTROLLER_LOGINCONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_LOGINCONTROLLERCREATOR_H


#include "ControllerCreator.h"

namespace http::server {
class LoginControllerCreator : public ControllerCreator {
public:
  LoginControllerCreator();
  std::shared_ptr<Controller> createController() override = 0;
};
}

#endif
