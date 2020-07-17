/**
 * @file base_object.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-07-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <string>

class BaseObject
{
private:
  unsigned int vnum_;
  std::string name_;
  std::string description_;

public:
  BaseObject();
  ~BaseObject() = default;
};