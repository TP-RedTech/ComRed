#ifndef COMREDSERVER_CONNECTION_H
#define COMREDSERVER_CONNECTION_H

#include "handleRequest.h"

#include <iostream>

namespace server {
class Connection : public std::enable_shared_from_this<Connection> {
public:
  explicit Connection(tcp::socket &&socket)
      : stream_(std::move(socket)), lambda_(*this) {
  }

  void run() {
    doRead();
  }

  void
  doRead() {
    req_ = {};

    stream_.expires_after(std::chrono::seconds(30));

    http::async_read(stream_, buffer_, req_,
                     beast::bind_front_handler(
                         &Connection::onRead,
                         shared_from_this()));
  }

  void onRead(
      beast::error_code ec,
      std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec == http::error::end_of_stream)
      return doClose();

    if (ec)
      return fail(ec, "read");

    handleRequest(std::move(req_), lambda_);
  }

  void onWrite(
      bool close,
      beast::error_code ec,
      std::size_t bytes_transferred) {
    boost::ignore_unused(bytes_transferred);

    if (ec)
      return fail(ec, "write");

    if (close) {
      return doClose();
    }

    res_ = nullptr;

    doRead();
  }

  void
  doClose() {
    beast::error_code ec;
    stream_.socket().shutdown(tcp::socket::shutdown_send, ec);

  }
private:
  struct SendLambda {
    Connection &self_;

    explicit
    SendLambda(Connection &self)
        : self_(self) {
    }

    template<bool isRequest, class Body, class Fields>
    void operator()(http::message<isRequest, Body, Fields> &&msg) const {
      auto sp = std::make_shared<
          http::message<isRequest, Body, Fields >>(std::move(msg));

      self_.res_ = sp;

      http::async_write(
          self_.stream_,
          *sp,
          beast::bind_front_handler(
              &Connection::onWrite,
              self_.shared_from_this(),
              sp->need_eof()));
    }
  };

  beast::tcp_stream stream_;
  beast::flat_buffer buffer_;
  std::shared_ptr<std::string const> doc_root_;
  http::request<http::string_body> req_;
  std::shared_ptr<void> res_;
  SendLambda lambda_;

};
}

#endif //COMREDSERVER_INCLUDE_SERVER_CONNECTION_H
