
#include "controller/DeleteControllerCreator.h"
http::server::DeleteControllerCreator::DeleteControllerCreator() {

}
std::shared_ptr<Controller> http::server::DeleteControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
