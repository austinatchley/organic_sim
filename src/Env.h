#pragma once

#include <vector>

class Env {
  std::vector<int> m_targets;

public:
  Env(const std::vector<int>& targets) : m_targets(targets) {}
};
