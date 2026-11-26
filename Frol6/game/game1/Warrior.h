#pragma once
#include "NPC.h"
#include "Weapon.h"
#include <vector>
#include <string>

class Warrior : virtual public NPC {
protected:
    short strenght{21};
    std::vector<Weapon> weapons;

public:
    Warrior();
    Warrior(const std::string& name, unsigned int level = 1);
    void Create() override;
    void GetInfo() const override;
    void GetWeapon();
    void Recalculate() override;
    ~Warrior() override;
};
