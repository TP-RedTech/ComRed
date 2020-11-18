#include <iostream>
#include "server/Server.h"

int main()
{
  http::server::Server s("localhost", 5555);
  s.run();
}