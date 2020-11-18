#ifndef COMREDSERVER_SERVER_H
#define COMREDSERVER_SERVER_H

class Client {
public:
  Client() = default;
  virtual void run() = 0;
};

#endif
