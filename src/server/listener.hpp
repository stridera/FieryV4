#pragma once

#include <boost/asio.hpp>

namespace Mud::Server {

using tcp = boost::asio::ip::tcp;

template<class SessionType>
class Listener : public std::enable_shared_from_this<Listener<SessionType>>
{
public:
  Listener(boost::asio::io_context &io_context, const unsigned short port);

  void start();

private:
  void do_accept();

  tcp::socket socket_;
  tcp::acceptor acceptor_;
  boost::asio::streambuf input_buffer_;
};

}// namespace Mud::Server