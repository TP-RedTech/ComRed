#include "controller/LogoutControllerCreator.h"
http::server::LogoutControllerCreator::LogoutControllerCreator() {

}
std::shared_ptr<Controller> http::server::LogoutControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
