#ifndef COMREDSERVER_HANDLE_REUEST_H
#define COMREDSERVER_HANDLE_REUEST_H

#include "controller/controllers.h"
#include "BeastServerHeader.h"
#include "BasicResponses.h"

#include <memory>
#include <iostream>

namespace server {
void fail(beast::error_code ec, char const *what) {
  std::cerr << what << ": " << ec.message() << "\n";
}

template<class Body, class Allocator, class Send>
void handleRequest(http::request<Body, http::basic_fields<Allocator>> &&req,
                   Send &&send) {
  std::shared_ptr<Controller> controller;
  std::cout << req.target() << std::endl;
  if (req.method() == http::verb::get && req.target() == "/connect") {
    controller = std::make_shared<ConnectController>();
  } else if (req.method() == http::verb::post && req.target() == "/edit") {
    controller = std::make_shared<EditController>();
  } else if (req.method() == http::verb::post && req.target() == "/delete") {
    controller = std::make_shared<DeleteController>();
  } else if (req.method() == http::verb::post && req.target() == "/create") {
    controller = std::make_shared<CreateController>();
  }

  if (controller)
    return send(controller->handleRequest(move(req)));
  return send(BasicResponses::badRequest(req, "Unknown request"));
}
}

#endif //COMREDSERVER_INCLUDE_SERVER_REQUESTS_HANDLEREQUEST_H