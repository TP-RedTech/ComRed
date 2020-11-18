#include "controller/RegistrationControllerCreator.h"

http::server::RegistrationControllerCreator::RegistrationControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::RegistrationControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
