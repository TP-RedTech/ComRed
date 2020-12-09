#ifndef COMREDSERVER_REQUESTHANLDER_H
#define COMREDSERVER_REQUESTHANLDER_H

namespace http {
template<typename Request, typename Reply>
class RequestHandler {
public:
  RequestHandler() = default;

  RequestHandler(const RequestHandler &) = default;

  RequestHandler &operator=(const RequestHandler &) = default;
  virtual Reply handle(const Request &request) = 0;
};
}

#endif
