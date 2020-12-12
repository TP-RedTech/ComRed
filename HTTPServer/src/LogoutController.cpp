#include "server/controller/LogoutController.h"

namespace server {
http::response <http::string_body> server::LogoutController::handleRequest(http::request <http::string_body> &&request) {
  http::response<http::string_body> res;
  return res;
}
}
