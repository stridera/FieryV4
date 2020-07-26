#pragma once

#include "../server/connection_base.hpp"

namespace Mud::Player::Connection {
class Connection : public Server::ConnectionBase
{
public:
  Connection(){};
  ~Connection() = default;

private:
};

}// namespace Mud::Player::Connection
