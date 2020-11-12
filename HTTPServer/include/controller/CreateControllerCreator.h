#ifndef COMREDSERVER_INCLUDE_CONTROLLER_CREATECONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_CREATECONTROLLERCREATOR_H

#include "ControllerCreator.h"

namespace http::server
{
class CreateControllerCreator : ControllerCreator {
public:
  CreateControllerCreator();
  std::shared_ptr<Controller>createController() override;
};
}

#endif
