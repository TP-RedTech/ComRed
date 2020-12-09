#include "server/Server.h"

#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>

#include <memory>
#include <iostream>
#include <vector>
#include <thread>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

namespace server {

template<class Body, class Allocator, class Send>
class RequestHandler {
public:
  virtual void handle(http::request<Body, http::basic_fields<Allocator>> &&req, Send &&send) = 0;
};

template<class Body, class Allocator, class Send>
class ComredRequestHandler {
public:
  void handle(http::request<Body, http::basic_fields<Allocator>> &&req, Send &&send) override {

    auto const bad_request =
        [&req](beast::string_view why) {
          http::response<http::string_body> res{http::status::bad_request, req.version()};
          res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
          res.keep_alive(req.keep_alive());
          res.body() = std::string(why);
          res.prepare_payload();
          return res;
        };
  }
};

// This function produces an HTTP response for the given
// request. The type of the response object depends on the
// contents of the request, so the interface requires the
// caller to pass a generic lambda for receiving the response.
template<class Body, class Allocator, class Send>
void handle_request(http::request<Body, http::basic_fields<Allocator>> &&req,
                    Send &&send) {
  // Returns a bad request response
  auto const bad_request =
      [&req](beast::string_view why) {
        http::response<http::string_body> res{http::status::bad_request, req.version()};
        res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
        res.keep_alive(req.keep_alive());
        res.body() = std::string(why);
        res.prepare_payload();
        return res;
      };
  return send(bad_request("Meow meow\n"));
}

void fail(beast::error_code ec, char const *what) {
  std::cerr << what << ": " << ec.message() << "\n";
}

// Handles an HTTP server connection
class Session : public std::enable_shared_from_this<Session> {
public:
  // Take ownership of the stream
  explicit Session(tcp::socket &&socket)
      : stream_(std::move(socket)), lambda_(*this) {
  }

  // Start the asynchronous operation
  void run() {
    do_read();
  }

  void do_read() {
    // Make the request empty before reading,
    // otherwise the operation behavior is undefined.
    req_ = {};

    // Set the timeout.
    stream_.expires_after(std::chrono::seconds(30));

    // Read a request
    http::async_read(stream_, buffer_, req_,
                     beast::bind_front_handler(
                         &Session::on_read,
                         shared_from_this()));
  }

  void on_read(beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    // This means they closed the connection
    if (ec == http::error::end_of_stream)
      return do_close();

    if (ec)
      return fail(ec, "read");

    // Send the response
    handle_request(std::move(req_), lambda_);
  }

  void on_write(bool close, beast::error_code ec, std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec)
      return fail(ec, "write");

    if (close) {
      // This means we should close the connection, usually because
      // the response indicated the "Connection: close" semantic.
      return do_close();
    }

    // We're done with the response so delete it
    res_ = nullptr;

    // Read another request
    do_read();
  }

  void do_close() {
    // Send a TCP shutdown
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);

    // At this point the connection is closed gracefully
  }
private:
  // This is the C++11 equivalent of a generic lambda.
  // The function object is used to send an HTTP message.
  struct send_lambda {
    Session &self_;

    explicit send_lambda(Session &self)
        : self_(self) {
    }

    template<bool isRequest, class Body, class Fields>
    void operator()(http::message<isRequest, Body, Fields> &&msg) const {
      // The lifetime of the message has to extend
      // for the duration of the async operation so
      // we use a shared_ptr to manage it.
      auto sp = std::make_shared<http::message<isRequest, Body, Fields>>(std::move(msg));

      // Store a type-erased version of the shared
      // pointer in the class to keep it alive.
      self_.res_ = sp;

      // Write the response
      http::async_write(
          self_.stream_,
          *sp,
          beast::bind_front_handler(
              &Session::on_write,
              self_.shared_from_this(),
              sp->need_eof()));
    }
  };

  beast::tcp_stream stream_;
  beast::flat_buffer buffer_;
  http::request<http::string_body> req_;
  std::shared_ptr<void> res_;
  send_lambda lambda_;

};

// Accepts incoming connections and launches the sessions
class Listener : public std::enable_shared_from_this<Listener> {
public:
  Listener(
      net::io_context &ioc,
      tcp::endpoint endpoint)
      : ioc_(ioc), acceptor_(net::make_strand(ioc)) {
    beast::error_code ec;

    // Open the acceptor
    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
      fail(ec, "open");
      return;
    }

    // Allow address reuse
    acceptor_.set_option(net::socket_base::reuse_address(true), ec);
    if (ec) {
      fail(ec, "set_option");
      return;
    }

    // Bind to the server address
    acceptor_.bind(endpoint, ec);
    if (ec) {
      fail(ec, "bind");
      return;
    }

    // Start listening for connections
    acceptor_.listen(
        net::socket_base::max_listen_connections, ec);
    if (ec) {
      fail(ec, "listen");
      return;
    }
  }

  // Start accepting incoming connections
  void run() {
    do_accept();
  }

private:
  void do_accept() {
    // The new connection gets its own strand
    acceptor_.async_accept(
        net::make_strand(ioc_),
        beast::bind_front_handler(
            &Listener::on_accept,
            shared_from_this()));
  }

  void on_accept(beast::error_code ec, tcp::socket socket) {
    if (ec) {
      fail(ec, "accept");
    } else {
      // Create the Session and run it
      std::make_shared<Session>(std::move(socket))->run();
    }

    // Accept another connection
    do_accept();
  }

private:
  net::io_context &ioc_;
  tcp::acceptor acceptor_;
};

Server::Server(const std::string &addr, unsigned short port) : address_(addr), port_(port), context_(1) {
}

void Server::run() {
  std::make_shared<Listener>(context_, tcp::endpoint{net::ip::make_address(address_), port_})->run();
  context_.run();
//  std::vector<std::thread> v;
//  v.reserve(threads - 1);
//  for (size_t i = threads - 1; i > 0; --i) {
//    v.emplace_back([&ioc] {
//      ioc.run();
//    });
//  }
}

void Server::setAccept() {
}

}