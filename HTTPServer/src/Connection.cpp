#include "server/Connection.h"

using namespace std;
using namespace boost::asio;

namespace http {
namespace server {

Connection::Connection(ip::tcp::socket socket,
                       ConnectionManager &manager,
                       RequestHandler &handler) :
    socket_(move(socket)), connectionManager_(manager), requestHandler_(handler) {
}

void Connection::read() {
  auto self(shared_from_this());
  socket_.async_read_some(boost::asio::buffer(buffer_),
                          [this, self](boost::system::error_code ec, std::size_t bytes_transferred)
                          {
                            if (!ec)
                            {
                              RequestParser::result_type result;
                              std::tie(result, std::ignore) = RequestParser.parse(
                                  request_, buffer_.data(), buffer_.data() + bytes_transferred);

                              if (result == RequestParser::good)
                              {
                                reply_ = requestHandler_.handle(request_);
                                write();
                              }
                              else if (result == request_parser::bad)
                              {
                                reply_ = reply::stock_reply(reply::bad_request);
                                do_write();
                              }
                              else
                              {
                                do_read();
                              }
                            }
                            else if (ec != boost::asio::error::operation_aborted)
                            {
                              connection_manager_.stop(shared_from_this());
                            }
                          });

}

void Connection::write() {

}

void Connection::start() {
  read();
}

void Connection::stop() {
  socket_.close();
}
}
}
