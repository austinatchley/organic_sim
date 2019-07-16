#pragma once

#include <map>

namespace Constants {
  const static int NUM_CREATURES = 10;

  const static int SIZE =   0;
  const static int HEALTH = 1;
  const static int COLOR =  2;
  const static int SPEED =  3;

  const static double MAX_FPS = 60.0;
  const static double MAX_STEP_USEC =  100000.0 / MAX_FPS;

  enum class CMD_OPTION {
    Noop,
    Debug,
  };

  const static std::map<std::string, CMD_OPTION> stringToCmdOption =
  {
    {"-d", CMD_OPTION::Debug}
  };

  static CMD_OPTION convertStringToCmdOption(const std::string& s) {
    if (s.empty()) {
      return CMD_OPTION::Noop;
    }

    if (stringToCmdOption.find(s) != stringToCmdOption.end()) {
      return stringToCmdOption.at(s);
    } else {
      return CMD_OPTION::Noop;
    }
  }
}
