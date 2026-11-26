#pragma once
#include "Warrior.h"
#include "Wizard.h"

class Paladin : public Warrior, public Wizard
{
public:
    Paladin();
    void Create() override;
    void GetInfo() override;
    ~Paladin() override;
};
