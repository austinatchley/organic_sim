#include <iostream>

#include "OrganicSim.h"

int main(int argc, char** argv) {
  Env env;
  OrganicSim sim = OrganicSim(&env);

  int step = 0;
  while(1) {
    std::cout << "Step " << ++step << std::endl;
    sim.step();
  }
};
