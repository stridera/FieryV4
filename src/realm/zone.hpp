#pragma once

#include <vector>

#include "room.hpp"
#include "weather.hpp"

class Zone : BaseObject
{
private:
  unsigned int lifespan;
  unsigned int age;
  Weather weather;

  std::vector<Room> _rooms;

public:
  Zone();
  ~Zone() = default;
};
