#include "controller/DeleteControllerCreator.h"
#include "controller/DeleteController.h"

http::server::DeleteControllerCreator::DeleteControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::DeleteControllerCreator::createController() {
  return std::make_shared<DeleteController>();
}
