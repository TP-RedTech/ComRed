#include "server/controller/ConnectController.h"

namespace server {
http::response <http::string_body> server::ConnectController::handleRequest(http::request <http::string_body> &&request) {
  http::response<http::string_body> res;
  res.keep_alive(request.keep_alive());
  res.body() = "Connected";
  res.prepare_payload();
  return res;
}
}
