#pragma once

#include <vector>

#include "../base_object.hpp"
#include "zone.hpp"

class Realm : BaseObject
{
private:
  std::vector<Zone> _zones;

public:
  // realm(/* args */);
  // ~realm();
};
