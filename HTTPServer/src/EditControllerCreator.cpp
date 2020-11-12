#include "controller/EditControllerCreator.h"
http::server::EditControllerCreator::EditControllerCreator() {

}
std::shared_ptr<Controller> http::server::EditControllerCreator::createController() {
  return std::shared_ptr<Controller>();
}
