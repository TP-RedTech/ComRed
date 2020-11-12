#include "controller/ConnectControllerCreator.h"
http::server::ConnectControllerCreator::ConnectControllerCreator() {

}
std::shared_ptr<Controller> http::server::ConnectControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
