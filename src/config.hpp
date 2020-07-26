#pragma once

#include <string_view>
namespace config {

constexpr std::string_view version("4.0.0");

const unsigned short default_port = 4000;
const unsigned short default_api_port = 5000;


constexpr std::string_view compile_date = __DATE__;
constexpr std::string_view compile_time = __TIME__;

}