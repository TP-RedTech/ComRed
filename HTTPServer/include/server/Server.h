#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

#include <string>
#include <vector>

#include <boost/asio/io_context.hpp>

namespace server {
class Server {
public:
  Server(const std::string &addr,
         unsigned short port, int threads);

  void run();

private: // functions
  void setAccept();

private: // functions
  std::string address_;
  unsigned short port_;
  boost::asio::io_context context_;
  int threads_;
};

}

#endif //COMREDSERVER_SERVER_H
