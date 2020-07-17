#pragma once

#include <memory>

#include "../base_object.hpp"

class Room;

class Player : BaseObject
{
private:
  std::shared_ptr<Room> in_room_;
  std::shared_ptr<Room> was_in_room_;

public:
  Player() = default;
  ~Player() = default;
};
