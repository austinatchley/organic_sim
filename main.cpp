#include <iostream>
#include <vector>
#include <chrono>
#include <unistd.h>

#include "Constants.h"
#include "OrganicSim.h"
#include "BasicCreature.h"

static bool debug = false;

void handleCmdArgs(int argc, char** argv);
std::vector<CreaturePtr> buildCreatures();
void printInfo(const Env& env, const std::vector<CreaturePtr>& creatures, const OrganicSim& sim, int step, double dt);

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
  std::vector<CreaturePtr> creatures = std::move(buildCreatures());
  OrganicSim sim = OrganicSim(env, creatures);

  int step = 0;
  auto lastTime = std::chrono::system_clock::now();

  while(1) {
    auto time = std::chrono::system_clock::now();
    auto dt = time - lastTime;

    if (dt.count() < Constants::MAX_STEP_USEC) {
        continue; // cap the rate at which we update
    }
    lastTime = time;

    printInfo(env, creatures, sim, ++step, dt.count());
    sim.step();
  }
}

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

std::vector<CreaturePtr> buildCreatures() {
  std::vector<CreaturePtr> creatures;

  for (int i = 0; i < Constants::NUM_CREATURES; ++i) {
    creatures.push_back(new BasicCreature());
  }

  return std::move(creatures);
}

void printInfo(const Env& env, const std::vector<CreaturePtr>& creatures, const OrganicSim& sim, int step, double dt) {
  std::cout << "Step " << step << std::endl;

  if (debug) {
    std::cout << "Microseconds elapsed: " << dt << std::endl;
    std::cout << "Creatures remaining: " << creatures.size() << std::endl;

    for (int i = 0; i < creatures.size(); ++i) {
      const CreaturePtr c = creatures.at(i);
      if (c != nullptr) {
        std::cout << "Creature " << i << ": " << c->printInfo() << std::endl;
      }
    }
  }

  std::cout << "---------------" << std::endl;
}
