#include "server/ConnectionManager.h"

using namespace std;
using namespace boost::asio;

namespace http {
namespace server {
void ConnectionManager::start(ConnectionPtr c) {
  connections_.insert(c);
  c->start();
}

void ConnectionManager::stop(ConnectionPtr c) {
  connections_.erase(c);
  c->stop();
}

void ConnectionManager::stopAll() {
  for (auto c: connections_)
    c->stop();
  connections_.clear();
}

}
}
