#include "controller/LoginControllerCreator.h"
#include "controller/LoginController.h"

http::server::LoginControllerCreator::LoginControllerCreator() {

}

std::shared_ptr<http::server::Controller> http::server::LoginControllerCreator::createController() {
  return std::make_shared<LoginController>();
}
