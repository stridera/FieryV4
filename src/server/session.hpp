#pragma once

#include <boost/asio.hpp>
#include <memory>

#include "../players/player.hpp"

namespace Mud::Server {

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session>
{
public:
  explicit Session(tcp::socket socket) : socket_(std::move(socket))
  {
  }

  void start() {}

private:
  tcp::socket socket_;
  std::shared_ptr<Player::Player> player_ = nullptr;
};

}// namespace Mud::Server