#pragma once
#include "Warrior.h"
#include "Wizard.h"

class Paladin : public Warrior, public Wizard {
public:
    Paladin();
    void Create() override;
    void GetInfo() const override;
    void Recalculate() override;
    ~Paladin() override;
};
