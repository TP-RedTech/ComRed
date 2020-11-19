#ifndef COMREDSERVER_INCLUDE_CONTROLLER_LOGOUTCONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_LOGOUTCONTROLLERCREATOR_H

#include "ControllerCreator.h"

namespace http { namespace server {
class LogoutControllerCreator : public ControllerCreator {
public:
  LogoutControllerCreator();
  std::shared_ptr<Controller> createController() override;
};
} }

#endif
