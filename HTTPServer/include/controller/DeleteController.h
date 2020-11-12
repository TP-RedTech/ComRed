#ifndef COMREDSERVER_DELETECONTROLLER_H
#define COMREDSERVER_DELETECONTROLLER_H

#include "requests/Request.h"
#include "requests/Reply.h"
#include "BaseController.h"

namespace http::server {
class DeleteController : public BaseController {
public:
  DeleteController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
