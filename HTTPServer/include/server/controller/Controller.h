#ifndef COMREDSERVER_BASECONTROLLER_H
#define COMREDSERVER_BASECONTROLLER_H

#include <boost/beast.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>

namespace server {

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class Controller {
public:
  Controller() = default;
  virtual http::response<http::string_body> handleRequest(http::request <http::string_body> &&request) = 0;
};
}

#endif //COMREDSERVER_BASECONTROLLER_H
