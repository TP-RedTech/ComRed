#ifndef COMREDSERVER_CONTROLLER_CREATOR_H
#define COMREDSERVER_CONTROLLER_CREATOR_H

#include "requests/Request.h"
#include "requests/Reply.h"
#include "Controller.h"
#include <memory>

namespace http { namespace server {
class ControllerCreator {
public:
  ControllerCreator();
  virtual std::shared_ptr<Controller> createController() = 0;
};
} }

#endif //COMREDSERVER_BASECONTROLLER_H
