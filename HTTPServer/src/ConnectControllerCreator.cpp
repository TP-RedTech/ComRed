#include "controller/ConnectControllerCreator.h"
http::server::ConnectControllerCreator::ConnectControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::ConnectControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
