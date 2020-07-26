#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../base_object.hpp"
#include "../objects/object.hpp"
#include "../players/player.hpp"
#include "exits.hpp"

namespace Mud::Room {

class Zone;

enum class RoomFlag {
  dark,// Room is dark
  alwayslit,// Makes the room lit
  indoors,// Indoors
  peaceful,// Violence not allowed
  godroom,// LVL_GOD+ only allowed
  death,// Death Trap
  nomob,// MOBs not allowed
  soundproof,// Shouts, gossip blocked
  notrack,// Track won't go through
  nomagic,// Magic not allowed
  noport,// Can't teleport in
  nowell,// No spell portals like moonwell
  norecall,// No recalling
  nosummon,// Can't summon to or from. Can't banish here.
  noscan,// Unable to scan to/from rooms
  arena,// (safe) PK allowed in room
  observatory,// see into adjacent ARENA rooms

  COUNT// Keep at the bottom
};

class Room : BaseObject
{
private:
  std::shared_ptr<Zone> zone_;
  std::vector<Exit::Exit> exits_;
  std::unordered_map<std::string, std::string> extra_descriptions_;
  std::vector<RoomFlag> flags_;

  std::vector<std::shared_ptr<Player::Player>> players_;
  std::vector<std::shared_ptr<Object::Object>> objects_;

public:
  Room() = default;
  ~Room() = default;
};

}