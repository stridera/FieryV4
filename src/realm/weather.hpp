#pragma once

#include "../constants.hpp"

enum class Hemisphere {
  northwest,
  northeast,
  southwest,
  southeast,

  COUNT// Keep at end
};

enum class Climate {
  none,
  semiarid,
  arid,
  oceanic,
  temperate,
  subtropical,
  tropical,
  subarctic,
  arctic,
  alpine,

  COUNT// Keep at end
};

struct Weather
{
  const Hemisphere hemisphere;
  const Climate climate;

  int temperature;
  unsigned int precipitation;
  unsigned int wind_speed;
  Direction wind_direction;
};