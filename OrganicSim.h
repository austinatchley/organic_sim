#pragma once 
#include <vector>
#include <memory>

#include "Env.h"
#include "Creature.h"

class OrganicSim {
private:
  Env m_env;
  std::vector<Creature> m_creatures;


public:
  OrganicSim(const Env& env, const std::vector<Creature>& creatures) : 
    m_env(env), m_creatures(creatures) {}

  void step();
};
