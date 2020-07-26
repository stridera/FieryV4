#include "config.hpp"
#include "fiery.hpp"
#include "logging/log.hpp"
#include <docopt/docopt.h>
#include <functional>
#include <iostream>
#include <map>


static constexpr auto USAGE =
  R"(Fierymud

    Usage:
          fierymud [--port=<port>]
          fierymud --version
    Options:
          -h --help     Show this screen.
          --version     Show version.
          --port=<port>  Port [default: 4000].
          --api_port=<api_port>  Api Port [default: 5000]
)";

int main(int argc, const char **argv)
{
  std::string version(config::version);
  std::map<std::string, docopt::value> args = docopt::docopt(USAGE,
    { std::next(argv), std::next(argv, argc) },
    true,// show help if requested
    version);// version string

  unsigned short port = config::default_port;
  if (args["--port"]) {
    try {
      port = static_cast<unsigned short>(args["--port"].asLong());
    } catch (...) {
    }
  }

  unsigned short api_port = config::default_api_port;
  if (args["--api_port"]) {
    try {
      api_port = static_cast<unsigned short>(args["--api_port"].asLong());
    } catch (...) {
    }
  }

  Mud::Logger::getLogger()->info("Running on port {}.\n", port);
  Mud::Logger::getLogger()->info("API on port {}.\n", api_port);

  Mud::Fiery fiery(port, api_port);
  fiery.run();

  return 0;
}