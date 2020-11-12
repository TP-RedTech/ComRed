
#include "controller/CreateControllerCreator.h"
http::server::CreateControllerCreator::CreateControllerCreator() {

}
std::shared_ptr<Controller> http::server::CreateControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
