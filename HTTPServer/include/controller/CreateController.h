#ifndef COMREDSERVER_CREATECONTROLLER_H
#define COMREDSERVER_CREATECONTROLLER_H

#include "BaseController.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class CreateController : public BaseController {
public:
  CreateController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
