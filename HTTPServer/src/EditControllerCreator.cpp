#include "controller/EditControllerCreator.h"
http::server::EditControllerCreator::EditControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::EditControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
