#ifndef COMREDSERVER_BASECONTROLLER_H
#define COMREDSERVER_BASECONTROLLER_H

#include <boost/beast/http/message.hpp>
#include <boost/beast/http.hpp>


namespace server {

using Request=boost::beast::http::request<boost::beast::http::string_body>;
using Reply=boost::beast::http::response<boost::beast::http::string_body>;

class Controller {
public:
  Controller();
  virtual Reply handleRequest(Request request) = 0;
};
}

#endif //COMREDSERVER_BASECONTROLLER_H
