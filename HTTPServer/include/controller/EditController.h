#ifndef COMREDSERVER_EDITCONTROLLER_H
#define COMREDSERVER_EDITCONTROLLER_H

#include "BaseController.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class EditController : public BaseController {
public:
  EditController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
