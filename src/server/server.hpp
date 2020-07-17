#pragma once

#include <boost/asio.hpp>
#include "session.hpp"

using boost::asio::ip::tcp;

class Server
{
public:
  Server(boost::asio::io_context &io_context, const unsigned short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
  {
    do_accept();
  }

private:
  void do_accept()
  {
    acceptor_.async_accept(
      [this](boost::system::error_code ec, tcp::socket socket) {
        if (!ec) {
          std::make_shared<Session>(std::move(socket))->start();
        }

        do_accept();
      });
  }

  tcp::acceptor acceptor_;
};
