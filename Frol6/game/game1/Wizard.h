#pragma once
#include "NPC.h"
#include "Spell.h"
#include <vector>
#include <string>

class Wizard : virtual public NPC {
protected:
    short intellect{29};
    std::vector<Spell> spells;

public:
    Wizard();
    Wizard(const std::string& name, unsigned int level = 1);
    void Create() override;
    void GetInfo() const override;
    void LearnSpell();
    void Recalculate() override;
    ~Wizard() override;
};
