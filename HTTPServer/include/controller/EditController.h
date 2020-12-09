#ifndef COMREDSERVER_EDITCONTROLLER_H
#define COMREDSERVER_EDITCONTROLLER_H

#include "Controller.h"

namespace server {
class EditController : public Controller {
public:
  EditController() = default;
  Reply handleRequest(Request request) override;
};
}

#endif
