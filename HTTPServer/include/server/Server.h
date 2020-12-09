#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

#include <string>
#include <boost/asio.hpp>

namespace server {
class Server {
public:
  Server(const std::string &addr,
         unsigned short port);

  void run();

private: // functions
  void setAccept();

private: // functions
  std::string address_;
  unsigned short port_;
  int threads;
  boost::asio::io_context context_;
};

}

#endif //COMREDSERVER_SERVER_H
