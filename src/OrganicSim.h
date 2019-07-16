#pragma once 
#include <vector>
#include <memory>

#include "Env.h"
#include "Creature.h"

class OrganicSim {
private:
  Env m_env;
  std::vector<CreaturePtr> m_creatures;


public:
  OrganicSim(const Env& env, const std::vector<CreaturePtr>& creatures) : 
    m_env(env), m_creatures(creatures) {}

  void step();
};
