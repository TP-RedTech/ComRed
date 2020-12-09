#include <iostream>
#include "server/Server.h"

int main()
{
  server::Server s("127.0.0.1", 5555);
  s.run();
}