#include "controller/LogoutControllerCreator.h"
#include "controller/LogoutController.h"

http::server::LogoutControllerCreator::LogoutControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::LogoutControllerCreator::createController() {
  return std::make_shared<LogoutController>();
}
