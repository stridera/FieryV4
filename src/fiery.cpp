#include "fiery.hpp"
#include <iostream>

Fiery::Fiery(const unsigned short port) : _mudServer(mud_io_context, port)
{
}

int Fiery::run()
{
  _state = GameState::RUNNING;
  while (_state == GameState::RUNNING) {
    std::cout << "Running...\n";
    break;
  }
  return 0;
}