#include "OrganicSim.h"

void OrganicSim::step() {
  for (CreaturePtr c : m_creatures) {
      if (c != nullptr) {
        c->step();
      }
  }
}
