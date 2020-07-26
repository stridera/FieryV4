#pragma once
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Mud {

class Logger
{
public:
  inline static std::shared_ptr<spdlog::logger> &getLogger()
  {
    if (!logger_) {
      spdlog::set_pattern("%^[%l] %n: %v%$");
      logger_ = spdlog::stdout_color_mt("FieryMUD", spdlog::color_mode::always);
      logger_->set_level(spdlog::level::trace);
    }
    return logger_;
  }

private:
  static std::shared_ptr<spdlog::logger> logger_;
};

#define LOG_TRACE(...) Logger::getLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) Logger::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) Logger::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Logger::getLogger()->error(__VA_ARGS__)

}// namespace Mud