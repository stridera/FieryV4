add_executable(fierymud 
  main.cpp 
  fiery.cpp
  base_object.cpp
  players/player.cpp
  realm/realm.cpp
  realm/zone.cpp
  realm/room.cpp
  realm/shop.cpp
  server/server.cpp
  server/session.cpp
  )
  
target_link_libraries(
  fierymud
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)

