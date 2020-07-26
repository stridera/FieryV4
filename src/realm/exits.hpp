#pragma once

#include <memory>
#include <string>

#include "../objects/object.hpp"

namespace Mud::Room::Exit {

class Room;

struct Exit
{
  std::string description;
  std::string keyword;
  std::shared_ptr<Object::Object> key;
  std::shared_ptr<Room> to_room;
};

}