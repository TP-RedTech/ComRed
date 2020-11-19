#ifndef COMREDSERVER_DELETECONTROLLER_H
#define COMREDSERVER_DELETECONTROLLER_H

#include "requests/Request.h"
#include "requests/Reply.h"
#include "Controller.h"

namespace http::server {
class DeleteController : public Controller {
public:
  DeleteController();
  Reply handleRequest(const Request &request) override;
};
}

#endif