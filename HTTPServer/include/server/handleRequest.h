#ifndef COMREDSERVER_HANDLE_REUEST_H
#define COMREDSERVER_HANDLE_REUEST_H

#include "controller/controllers.h"

#include <memory>
#include <iostream>

namespace server {
void fail(beast::error_code ec, char const *what) {
  std::cerr << what << ": " << ec.message() << "\n";
}

template<class Body, class Allocator, class Send>
void handleRequest(http::request<Body, http::basic_fields<Allocator>> &&req,
                   Send &&send) {
  auto const bad_request =
      [&req](beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = std::string(why);
        res.prepare_payload();
        return res;
      };

  auto const not_found =
      [&req](beast::string_view target) {
        http::response<http::string_body> res{http::status::not_found, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "The resource '" + std::string(target) + "' was not found.";
        res.prepare_payload();
        return res;
      };

  auto const server_error =
      [&req](beast::string_view what) {
        http::response<http::string_body> res{http::status::internal_server_error, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.set(http::field::content_type, "text/html");
        res.keep_alive(req.keep_alive());
        res.body() = "An error occurred: '" + std::string(what) + "'";
        res.prepare_payload();
        return res;
      };

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
  return send(bad_request("I don't know this"));
}
}

#endif //COMREDSERVER_INCLUDE_SERVER_REQUESTS_HANDLEREQUEST_H
