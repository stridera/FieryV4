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

if (WERROR)
  target_compile_options(fierymud PRIVATE ${WERROR_FLAG})
  message(STATUS "Using Error Flags: ${WERROR_FLAG}")
endif ()
if (PEDANTIC)
  target_compile_options(fierymud PRIVATE ${PEDANTIC_COMPILE_FLAGS})
    message(STATUS "Using Pedantic Flags: ${PEDANTIC_COMPILE_FLAGS}")
endif ()

target_link_libraries(
  fierymud
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)

