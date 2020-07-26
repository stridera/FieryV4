#include "listener.hpp"

#include "../logging/log.hpp"
#include "session.hpp"

namespace Mud::Server {

template<class SessionType>
Listener<SessionType>::Listener(boost::asio::io_context &io_context, const unsigned short port)
  : socket_(io_context),
    acceptor_(io_context, tcp::endpoint(tcp::v6(), port))
{}

template<class SessionType>
void Listener<SessionType>::start()
{
  do_accept();
}

template<class SessionType>
void Listener<SessionType>::do_accept()
{
  acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
    if (!ec) {
      std::make_shared<SessionType>(std::move(socket_))->start();
      do_accept();
    } else if (ec != boost::asio::error::operation_aborted) {
      Logger::getLogger()->error("async_accept failed with error {}.", ec.message());
    }
  });
}

template class Listener<Session>;
}// Namespace Mud::Server