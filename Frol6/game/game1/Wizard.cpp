#include "Wizard.h"
#include <iostream>

Wizard::Wizard() {
    damage = 27;
    health = 21;
    armor = 10;
}

Wizard::Wizard(const std::string& characterName, unsigned int level) : Wizard() {
    name = characterName;
    while (lvl < level) LvlUp();
}

void Wizard::Create() {
    std::cout << "Вы создали мага\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    LearnSpell();
}

void Wizard::GetInfo() const {
    NPC::GetInfo();
    std::cout << "Интеллект: " << intellect << '\n';
}

void Wizard::LearnSpell() {
    if (spells.empty()) spells.push_back({"Вспышка", 1});
    std::cout << name << " изучил заклинание " << spells.front().name << '\n'
              << "Добавка к урону = " << spells.front().damage << '\n';
}

void Wizard::Recalculate() {
    const auto increase = static_cast<unsigned int>(1 + lvl * intellect * 0.1);
    damage += increase;
    health += increase;
    armor += increase;
}

Wizard::~Wizard() {
    std::cout << name << " испускает дух\n";
}
