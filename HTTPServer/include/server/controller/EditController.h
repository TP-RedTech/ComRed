#ifndef COMREDSERVER_EDITCONTROLLER_H
#define COMREDSERVER_EDITCONTROLLER_H

#include "Controller.h"

namespace server {
class EditController : public Controller {
public:
  EditController() = default;
  http::response <http::string_body> handleRequest(http::request <http::string_body> &&request) override;
};
}

#endif
