#include "controller/CreateControllerCreator.h"
#include "controller/CreateController.h"

http::server::CreateControllerCreator::CreateControllerCreator() = default;

std::shared_ptr<http::server::Controller> http::server::CreateControllerCreator::createController() {
  return std::make_shared<CreateController>();
}
