#include "server/Server.h"

#include "server/Listener.h"

namespace server {

Server::Server(const std::string &addr,
               unsigned short port,
               int threads) :
    address_(addr),
    port_(port),
    threads_(threads),
    context_(threads) {
}

void Server::run() {
  std::make_shared<Listener>(context_, tcp::endpoint{net::ip::make_address(address_), port_})->run();
  net::io_context &ioc = context_;
  auto runContext = [&ioc] { ioc.run(); };
  if (threads_ > 1) {
    std::vector<std::thread> v;
    v.reserve(threads_ - 1);
    for (size_t i = threads_ - 1; i > 0; --i) {
      v.emplace_back(runContext);
    }
    ioc.run();
  } else
    ioc.run();
}

void Server::setAccept() {
}

}