#include "Wizard.h"
#include <iostream>
#include <utility>

Wizard::Wizard()
{
    damage = 27;
    health = 21;
    armor = 10;
}
Wizard::Wizard(std::string name, unsigned int lvl)
{
    this->name = std::move(name);
    for (unsigned int i = 1; i < lvl; ++i) LvlUp();
    this->lvl = static_cast<short>(lvl);
}
void Wizard::Create()
{
    std::cout << "Вы создали мага\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    LearnSpell();
}
void Wizard::GetInfo()
{
    NPC::GetInfo();
    std::cout << "Интеллект: " << intellect << std::endl;
}
void Wizard::LearnSpell()
{
    Spell spell;
    spell.damage = 1;
    spell.name = "Вспышка";
    spells.push_back(spell);
    std::cout << name << " изучил заклинание " << spells[0].name << std::endl;
    std::cout << "Добавка к урону = " << spells[0].damage << std::endl;
}
void Wizard::Recalculate()
{
    damage += static_cast<unsigned int>(1 + lvl * intellect * 0.1);
    health += static_cast<unsigned int>(1 + lvl * intellect * 0.1);
    armor += static_cast<unsigned int>(1 + lvl * intellect * 0.1);
}
Wizard::~Wizard()
{
    std::cout << name << " испускает дух" << std::endl;
}
