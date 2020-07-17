#include "config.hpp"
#include "fiery.hpp"
#include <docopt/docopt.h>
#include <functional>
#include <iostream>


static constexpr auto USAGE =
  R"(Fierymud

    Usage:
          fierymud [--port=<port>]
          fierymud --version
    Options:
          -h --help     Show this screen.
          --version     Show version.
          --port=<port>  Port [default: 4000].
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

  std::cout << "Running on port " << port << '\n';

  Fiery fiery(port);
  int ret = fiery.run();

  //Use the default logger (stdout, multi-threaded, colored)
  // spdlog::info("Hello, {}!", "World");

  // fmt::print("Hello, from {}\n", "{fmt}");

  return ret;
}
