#include <iostream>
#include <vector>

#include "Constants.h"
#include "OrganicSim.h"

int main(int argc, char** argv) {
  std::vector<int> targets;
  targets.insert(targets.begin() + Constants::SIZE, 100);
  targets.insert(targets.begin() + Constants::HEALTH, 100);
  targets.insert(targets.begin() + Constants::COLOR, 0xff0000);
  targets.insert(targets.begin() + Constants::SPEED, 100);

  Env env(targets);
  OrganicSim sim = OrganicSim(&env);

  int step = 0;
  while(1) {
    std::cout << "Step " << ++step << std::endl;
    sim.step();
  }
};
