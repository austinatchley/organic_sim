#pragma once

#include <map>

namespace Constants {
  const static int NUM_CREATURES = 10;

  const static int SIZE =   0;
  const static int HEALTH = 1;
  const static int COLOR =  2;
  const static int SPEED =  3;

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

    std::cout << "CONVERTING " << s << std::endl;

    if (stringToCmdOption.find(s) != stringToCmdOption.end()) {
      return stringToCmdOption.at(s);
    } else {
      return CMD_OPTION::Noop;
    }
  }
}
