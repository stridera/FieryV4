#pragma once

#include <boost/asio.hpp>

namespace Mud::Server {

using boost::asio::ip::tcp;


class ConnectionBase
{
public:
  ConnectionBase(const ConnectionBase &) = delete;
  ConnectionBase &operator=(const ConnectionBase &) = delete;

protected:
  ConnectionBase(tcp::socket socket) : socket_(std::move(socket)){};

private:
  // tcp::acceptor acceptor_;
  tcp::socket socket_;
};

}// namespace Mud::Server