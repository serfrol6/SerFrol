#include "Paladin.h"
#include <iostream>

Paladin::Paladin() {
    intellect = 25;
    strenght = 19;
    health = 25;
    damage = 25;
    armor = 15;
}

void Paladin::Create() {
    std::cout << "Вы создали паладина\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    LearnSpell();
    GetWeapon();
}

void Paladin::GetInfo() const {
    NPC::GetInfo();
    std::cout << "Сила: " << strenght << '\n'
              << "Интеллект: " << intellect << '\n';
}

void Paladin::Recalculate() {
    const auto increase = static_cast<unsigned int>(1 + lvl * (strenght + intellect) * 0.05);
    damage += increase;
    health += increase;
    armor += increase;
}

Paladin::~Paladin() {
    std::cout << "Паладин отправляется к праотцам\n";
}
