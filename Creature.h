#pragma once

#include <iostream>
#include <string>

class Creature {
public:
  void step();

  std::string printInfo() const;
};
