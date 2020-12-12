#ifndef COMREDSERVER_CREATECONTROLLER_H
#define COMREDSERVER_CREATECONTROLLER_H

#include "Controller.h"
namespace server {
class CreateController : public Controller {
public:
  CreateController() = default;
  http::response<http::string_body> handleRequest(http::request<http::string_body> &&request) override;
};
}

#endif