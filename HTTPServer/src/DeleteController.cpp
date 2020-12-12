#include "server/controller/DeleteController.h"

namespace server {
http::response <http::string_body> server::DeleteController::handleRequest(http::request <http::string_body> &&request) {
  http::response<http::string_body> res;
  res.keep_alive(request.keep_alive());
  res.body() = "Deleted";
  res.prepare_payload();
  return res;
}
}
