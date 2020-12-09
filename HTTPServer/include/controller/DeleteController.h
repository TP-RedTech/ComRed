#ifndef COMREDSERVER_DELETECONTROLLER_H
#define COMREDSERVER_DELETECONTROLLER_H

#include "Controller.h"

namespace server {
class DeleteController : public Controller {
public:
  DeleteController() = default;
  Reply handleRequest(const Request request) override;
};
}

#endif