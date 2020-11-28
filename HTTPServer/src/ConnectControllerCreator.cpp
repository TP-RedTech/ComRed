#include "controller/ConnectControllerCreator.h"
#include "controller/ConnectController.h"

http::server::ConnectControllerCreator::ConnectControllerCreator() = default;
std::shared_ptr<http::server::Controller> http::server::ConnectControllerCreator::createController() {
  return std::make_shared<ConnectController>();
}
