#include "controller/LogoutControllerCreator.h"
http::server::LogoutControllerCreator::LogoutControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::LogoutControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
