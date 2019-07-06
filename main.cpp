#include <iostream>
#include <vector>

#include "Constants.h"
#include "OrganicSim.h"

std::vector<Creature>&& buildCreatures() {
  std::vector<Creature> creatures;

  for (int i = 0; i < Constants::NUM_CREATURES; ++i) {
    creatures.push_back(Creature());
  }

  return move(creatures);
}

int main(int argc, char** argv) {
  std::vector<int> targets;
  targets.insert(targets.begin() + Constants::SIZE, 100);
  targets.insert(targets.begin() + Constants::HEALTH, 100);
  targets.insert(targets.begin() + Constants::COLOR, 0xff0000);
  targets.insert(targets.begin() + Constants::SPEED, 100);

  Env env(targets);
  std::vector<Creature> creatures = move(buildCreatures());
  OrganicSim sim = OrganicSim(env, creatures);

  int step = 0;
  while(1) {
    std::cout << "Step " << ++step << std::endl;
    sim.step();
  }
}
