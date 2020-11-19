#ifndef COMREDSERVER_EDITCONTROLLER_H
#define COMREDSERVER_EDITCONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http { namespace server {
class EditController : public Controller {
public:
  EditController();
  Reply handleRequest(const Request &request) override;
};
} }

#endif
