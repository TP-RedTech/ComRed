#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

#include <string>
#include <boost/asio.hpp>

namespace http { namespace server {
class Server {
public:
  explicit Server(const std::string &address,
                  int port);

  void run();
};
} }

#endif //COMREDSERVER_SERVER_H
