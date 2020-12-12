#include "server/controller/LoginController.h"

namespace server {
http::response <http::string_body> server::LoginController::handleRequest(http::request <http::string_body> &&request) {
  http::response<http::string_body> res;
  return res;
}
}
