#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

#include <string>
#include <boost/asio.hpp>

#include "ConnectionManager.h"

namespace http {
namespace server {

class Server {
public:
  Server(const std::string &address,
         int port);

  void run();

private: // functions
  void setAccept();

private: // functions
  boost::asio::io_context io_context_;
  boost::asio::ip::tcp::acceptor acceptor_;
  int port_;
  ConnectionManager connectionManager_;
  std::string address_;
};

}
}

#endif //COMREDSERVER_SERVER_H
