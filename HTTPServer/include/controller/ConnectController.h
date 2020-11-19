#ifndef COMREDSERVER_CONNECTCONTROLLER_H
#define COMREDSERVER_CONNECTCONTROLLER_H

#include "Controller.h"
#include "requests/Request.h"
#include "requests/Reply.h"

namespace http::server {
class ConnectController : public Controller {
public:
  ConnectController();
  Reply handleRequest(const Request &request) override;
};
}

#endif
