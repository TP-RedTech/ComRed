#include "server/controller/EditController.h"

namespace server {
http::response <http::string_body> server::EditController::handleRequest(http::request <http::string_body> &&request) {
  http::response<http::string_body> res;
  res.keep_alive(request.keep_alive());
  res.body() = "Edited\n";
  res.prepare_payload();
  std::cout << request.body() << std::endl;
  return res;
}
}
