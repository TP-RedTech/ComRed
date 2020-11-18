#include "controller/ConnectController.h"

http::server::ConnectController::ConnectController() = default;

http::Reply http::server::ConnectController::handleRequest(const http::Request &request) {
  return http::Reply();
}
