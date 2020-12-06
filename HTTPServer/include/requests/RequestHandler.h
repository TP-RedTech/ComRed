#ifndef COMREDSERVER_REQUESTHANLDER_H
#define COMREDSERVER_REQUESTHANLDER_H

#include "Request.h"
#include "Reply.h"

namespace http {
class RequestHandler {
public:
  RequestHandler() = default;

  RequestHandler(const RequestHandler &) = default;

  RequestHandler& operator=(const RequestHandler &) = default;
  virtual Reply handle(const Request &request);
};
}

#endif
