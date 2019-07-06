#include <iostream>
#include <vector>

#include "Constants.h"
#include "OrganicSim.h"

static bool debug = false;

void handleCmdArgs(int argc, char** argv) {
  for(int i = 1; i < argc; ++i) {
    std::string arg = std::string(argv[i]);

    switch (Constants::convertStringToCmdOption(arg)) {
      case Constants::CMD_OPTION::Debug:
        std::cout << "Debug mode enabled" << std::endl;
        debug = true;
        break;

      default:
        std::cout << "Unknown argument: " << arg << std::endl;
    }
  }
}

std::vector<Creature> buildCreatures() {
  std::vector<Creature> creatures;

  for (int i = 0; i < Constants::NUM_CREATURES; ++i) {
    creatures.push_back(Creature());
  }

  return std::move(creatures);
}

void printInfo(const Env& env, const std::vector<Creature>& creatures, const OrganicSim& sim, int step) {
  std::cout << "Step " << step << std::endl;

  if (debug) {
    std::cout << "Creatures remaining: " << creatures.size() << std::endl;

    for (int i = 0; i < creatures.size(); ++i) {
      const Creature& c = creatures.at(i);
      std::cout << "Creature " << i << ": " << c.printInfo() << std::endl;
    }
  }

  std::cout << "---------------" << std::endl;
}

int main(int argc, char** argv) {
  if (argc > 1) {
    handleCmdArgs(argc, argv);
  }

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
    printInfo(env, creatures, sim, ++step);
    sim.step();
  }
}
