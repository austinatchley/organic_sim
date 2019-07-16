#pragma once

#include "Creature.h"

class BasicCreature : public Creature<int> {
public:
    void step() override {}

    std::string printInfo() const override {
        return "";
    }
};
