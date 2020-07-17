#pragma once

#include <memory>
#include <string>

#include "../objects/object.hpp"

class Room;

struct Exit
{
  std::string description;
  std::string keyword;
  std::shared_ptr<Object> key;
  std::shared_ptr<Room> to_room;
};