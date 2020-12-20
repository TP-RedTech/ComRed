#include "server/Connection.h"

namespace server {

void Connection::run() {
  doRead();
}

void Connection::doRead() {
  req_ = {};

  stream_.expires_after(std::chrono::seconds(30));

  http::async_read(stream_, buffer_, req_,
                   beast::bind_front_handler(
                       &Connection::onRead,
                       shared_from_this()));
}

void Connection::onRead(
    beast::error_code ec,
    std::size_t bytes_transferred) {
  boost::ignore_unused(bytes_transferred);

  if (ec == http::error::end_of_stream)
    return doClose();

  if (ec)
    return fail(ec, "read");

  handleRequest(std::move(req_), lambda_);
}

void Connection::onWrite(bool close, beast::error_code ec, std::size_t bytes_transferred) {
  boost::ignore_unused(bytes_transferred);

  if (ec)
    return fail(ec, "write");

  if (close) {
    return doClose();
  }

  res_ = nullptr;

  doRead();
}

void Connection::doClose() {
  beast::error_code ec;
  std::cerr << "Closed\n" << endl;
  stream_.socket().shutdown(tcp::socket::shutdown_send, ec);
}

template<bool isRequest, class Body, class Fields>
void Connection::SendLambda::operator()(http::message<isRequest, Body, Fields> &&msg) const {
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
}
