#ifndef COMREDSERVER_CONNECTIONMANAGER_H
#define COMREDSERVER_CONNECTIONMANAGER_H

#include <memory>
#include <boost/asio.hpp>
#include <set>

#include "requests/RequestHandler.h"
#include "Connection.h"

namespace http {
namespace server {


class ConnectionManager {
public:
  ConnectionManager() = default;
  ConnectionManager(const ConnectionManager &) = delete;
  ConnectionManager &operator=(const ConnectionManager &) = delete;

  void start(ConnectionPtr c);

  void stop(ConnectionPtr c);

  void stopAll();

private:
  std::set<ConnectionPtr> connections_;
};

}
}

#endif //COMREDSERVER_INCLUDE_SERVER_CONNECTIONMANAGER_H
