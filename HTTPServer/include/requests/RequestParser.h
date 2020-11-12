#ifndef COMREDSERVER_REQUESTPARSER_H
#define COMREDSERVER_REQUESTPARSER_H

#include <string>
#include "Request.h"

namespace http{
class RequestParser {
  RequestParser();
  Request parseRequest(const std::string &requestString);
};
}

#endif //COMREDSERVER_REQUESTPARSER_H
