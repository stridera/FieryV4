#pragma once

#include <string>

#include "constants.hpp"
#include "server/server.hpp"
#include <boost/asio.hpp>

enum class GameState {
  BOOTING,
  RUNNING,
  RESTARTING,
  SHUTTING_DOWN,
};


/**
 * @brief The big cahoona.  The main game loops.  The king of the jungle.  You get it...
 * 
 */
class Fiery
{
public:
  explicit Fiery(const unsigned short port);
  ~Fiery() = default;

  int run();

private:
  bool _isWizlocked = false;
  GameState _state = GameState::BOOTING;

  boost::asio::io_context mud_io_context;
  Server _mudServer;
};