#ifndef COMREDSERVER_CONNECTION_H
#define COMREDSERVER_CONNECTION_H

#include <boost/asio.hpp>
#include <memory>
#include <array>

#include "requests/Request.h"
#include "requests/RequestHandler.h"
#include "requests/RequestParser.h"
#include "requests/Reply.h"

namespace http {
namespace server {

class ConnectionManager;

class Connection : public std::enable_shared_from_this<Connection> {
public:
  Connection(const Connection &) = delete;
  Connection &operator=(const Connection &) = delete;

  explicit Connection(boost::asio::ip::tcp::socket socket,
                      ConnectionManager &manager, RequestHandler &handler);

  void read();

  void write();

  void start();

  void stop();

private:
  boost::asio::ip::tcp::socket socket_;
  ConnectionManager &connectionManager_;
  RequestHandler &requestHandler_;

  RequestParser requestParser_;
  Request request_;
  Reply reply_;
  std::array<char, 8192> buffer_;
};

using ConnectionPtr = std::shared_ptr<Connection>;
}
}

#endif
