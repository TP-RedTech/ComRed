#include "controller/RegistrationControllerCreator.h"
#include "controller/RegistrationController.h"

http::server::RegistrationControllerCreator::RegistrationControllerCreator() {

}

std::shared_ptr<http::server::Controller> http::server::RegistrationControllerCreator::createController() {
  return std::make_shared<RegistrationController>();
}
