#ifndef COMREDSERVER_INCLUDE_CONTROLLER_EDITCONTROLLERCREATOR_H
#define COMREDSERVER_INCLUDE_CONTROLLER_EDITCONTROLLERCREATOR_H

#include "ControllerCreator.h"

namespace http { namespace server {
class EditControllerCreator : public ControllerCreator {
public:
  EditControllerCreator();
  std::shared_ptr<Controller> createController();
};
} }

#endif
