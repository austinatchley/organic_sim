#include "OrganicSim.h"

void OrganicSim::step() {
  for (Creature c : m_creatures) {
    c.step();
  }
}
