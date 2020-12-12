#ifndef COMREDSERVER_CONNECTCONTROLLER_H
#define COMREDSERVER_CONNECTCONTROLLER_H

#include "Controller.h"


namespace server {
class ConnectController : public Controller {
public:
  ConnectController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif
