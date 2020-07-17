#pragma once

#include <memory>

class Player;

class Group
{
private:
  std::shared_ptr<Player> leader_;
  std::vector<Player> followers_;

public:
  Group();
  ~Group() = default;
};