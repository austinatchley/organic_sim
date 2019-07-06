#pragma once 
#include <vector>
#include <memory>

#include "Env.h"
#include "Creature.h"

class OrganicSim {
private:
  std::unique_ptr<Env> m_env;
  std::vector<Creature> m_creatures;


public:
  OrganicSim(Env* env) : m_env(env) {
    m_creatures = std::vector<Creature>();
  }

  void step();
};
