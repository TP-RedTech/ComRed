#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

#include <string>

namespace http::server {
class Server {
public:
  explicit Server(const std::string &address,
                  const std::string &port);

  void run();
};
}

#endif //COMREDSERVER_SERVER_H
