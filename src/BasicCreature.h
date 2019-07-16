#pragma once

#include "Creature.h"

class BasicCreature : public Creature<int> {
public:
  BasicCreature(int data) : Creature<int>(data) {}

  void step() override;

  std::string printInfo() const override;
};
