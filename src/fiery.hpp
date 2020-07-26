#pragma once

#include <boost/asio.hpp>
#include <string_view>

#include "constants.hpp"
#include "realm/realm.hpp"
#include "server/listener.hpp"
#include "server/session.hpp"

namespace Mud {

/**
 * @brief The big cahoona.  The main game loop.  The king of the jungle.  You get it...
 */

class Fiery
{
public:
  explicit Fiery(const unsigned short mud_port, const unsigned short api_port)
    : realm_(),
      mudServer_(io_context_, mud_port),
      apiServer_(io_context_, api_port),
      tick_interval_(1),
      ticker_(io_context_, tick_interval_)
  {
  }

  ~Fiery() = default;

  void run()
  {
    tick();
    io_context_.run();
  }

  void tick()
  {
    realm_.tick();

    ticker_.expires_at(ticker_.expires_at() + tick_interval_);
    ticker_.async_wait([this](const boost::system::error_code &) {
      tick();
    });
  }

private:
  boost::asio::io_context io_context_;
  Realm::Realm realm_;
  Server::Listener<Server::Session> mudServer_;
  Server::Listener<Server::Session> apiServer_;
  boost::posix_time::seconds tick_interval_;
  boost::asio::deadline_timer ticker_;
};

}// Namespace Mud