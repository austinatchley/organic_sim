#pragma once

#include <iostream>
#include <string>

template <class T = int>
class Creature {
protected:
    T m_data;

public:
  Creature(T data) : m_data(data) {}

  virtual void step() = 0;

  virtual std::string printInfo() const = 0;
};

using CreaturePtr = Creature<>*;
