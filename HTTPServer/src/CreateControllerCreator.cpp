#include "controller/CreateControllerCreator.h"

http::server::CreateControllerCreator::CreateControllerCreator() = default;

std::shared_ptr<http::server::Controller> http::server::CreateControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
