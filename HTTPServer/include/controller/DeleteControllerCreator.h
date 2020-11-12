#ifndef COMREDSERVER_INCLUDE_CONTROLLER_DELETECONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_DELETECONTROLLERCREATOR_H

#include "ControllerCreator.h"

namespace http::server {
class DeleteControllerCreator : public ControllerCreator {
public:
  DeleteControllerCreator();
  std::shared_ptr<Controller> createController() override;
};
}

#endif
