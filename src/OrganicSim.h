#pragma once
#include <memory>
#include <vector>

#include "Creature.h"
#include "Env.h"

class OrganicSim {
private:
  Env m_env;
  std::vector<CreaturePtr> m_creatures;

public:
  OrganicSim(const Env& env, const std::vector<CreaturePtr>& creatures)
      : m_env(env), m_creatures(creatures) {}

  void step();
};
