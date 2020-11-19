#ifndef COMREDSERVER_INCLUDE_CONTROLLER_REGISTRATIONCONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_REGISTRATIONCONTROLLERCREATOR_H

#include "ControllerCreator.h"

namespace http { namespace server {
class RegistrationControllerCreator : public ControllerCreator {
public:
  RegistrationControllerCreator();
  std::shared_ptr<Controller> createController() override;
};
} }

#endif
