#include "CharacterFactory.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"

std::unique_ptr<NPC> CreateCharacter(PlayerClass playerClass)
{
    switch (playerClass)
    {
    case PlayerClass::Warrior: return std::make_unique<Warrior>();
    case PlayerClass::Wizard: return std::make_unique<Wizard>();
    case PlayerClass::Paladin: return std::make_unique<Paladin>();
    default: return nullptr;
    }
}
