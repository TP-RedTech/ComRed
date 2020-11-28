#include "controller/EditControllerCreator.h"
#include "controller/EditController.h"

http::server::EditControllerCreator::EditControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::EditControllerCreator::createController() {
  return std::make_shared<EditController>();
}
