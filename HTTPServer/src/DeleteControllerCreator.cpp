
#include "controller/DeleteControllerCreator.h"
http::server::DeleteControllerCreator::DeleteControllerCreator() {

}
std::shared_ptr<http::server::Controller> http::server::DeleteControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
