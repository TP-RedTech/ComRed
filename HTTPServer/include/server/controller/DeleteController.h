#ifndef COMREDSERVER_DELETECONTROLLER_H
#define COMREDSERVER_DELETECONTROLLER_H

#include "Controller.h"

namespace server {
class DeleteController : public Controller {
public:
  DeleteController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif