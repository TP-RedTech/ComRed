#include "server/Server.h"

#include <iostream>

using namespace std;
using namespace boost::asio;

namespace http {
namespace server {
Server::Server(const std::string &address, int port) : acceptor_(io_context_), port_(port), address_(address) {
  ip::tcp::endpoint endpoint(ip::tcp::v4(), port_);
  acceptor_.open(endpoint.protocol());
  acceptor_.set_option(ip::tcp::acceptor::reuse_address(true));
  acceptor_.bind(endpoint);
  acceptor_.listen();
  setAccept();
}

void Server::run() {
  cerr << "listen on port: " << port_ << endl;
  io_context_.run();
}

void Server::setAccept() {
  acceptor_.async_accept([this](boost::system::error_code ec, ip::tcp::socket socket) {
    if (!acceptor_.is_open())
      return;
    if (!ec) {
      // connection_manager.add(make_shared<Connection>(std::move(socket), connectionManager_, requestHandler));
    }
    setAccept();
  })
}

}
}