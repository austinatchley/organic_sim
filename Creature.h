#pragma once

#include <iostream>
#include <string>

template <class T = int>
class Creature {
private:
    T m_data;

public:
  virtual void step() = 0;

  virtual std::string printInfo() const = 0;
};

using CreaturePtr = Creature<>*;
