#pragma once

#include <vector>

#include "room.hpp"
#include "weather.hpp"

namespace Mud::Zone {


class Zone : BaseObject
{
private:
  unsigned int lifespan;
  unsigned int age;
  Weather weather;

  std::vector<Room::Room> _rooms;

public:
  Zone();
  ~Zone() = default;
};

}