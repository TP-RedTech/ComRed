
#ifndef COMREDSERVER_CONNECTCONTROLLERCREATOR_H
#define COMREDSERVER_CONNECTCONTROLLERCREATOR_H

#include <memory>
#include "Controller.h"

namespace http { namespace server {
class ConnectControllerCreator {
public:
  ConnectControllerCreator();
  virtual std::shared_ptr<Controller> createController();
};
} }

#endif //COMREDSERVER_INCLUDE_CONTROLLER_CONNECTCONTROLLERCREATOR_H
