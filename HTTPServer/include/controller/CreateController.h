#ifndef COMREDSERVER_CREATECONTROLLER_H
#define COMREDSERVER_CREATECONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class CreateController : public Controller {
public:
  CreateController();
  Reply handleRequest(const Request &request) override;
};
}

#endif