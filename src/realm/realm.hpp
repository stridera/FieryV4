#pragma once

#include <iostream>
#include <vector>

#include "../base_object.hpp"
#include "../npc/npc.hpp"
#include "../players/player.hpp"
#include "zone.hpp"

namespace Mud::Realm {

class Realm
{
public:
  Realm() noexcept {};
  ~Realm() = default;

  void tick()
  {
    std::cout << "Realm Tick\n";
  }

private:
  std::vector<Zone::Zone> _zones;

  std::vector<std::shared_ptr<Player::Player>> _players;// Players are owned by the realm.
  std::vector<std::weak_ptr<NPC::NPC>> _npcs;// NPC's are owned by their room.  If they die, they are removed there.
};

}// namespace Mud::Realm