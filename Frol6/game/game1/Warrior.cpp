#include "Warrior.h"
#include <iostream>

Warrior::Warrior() {
    damage = 20;
    health = 30;
    armor = 15;
}

Warrior::Warrior(const std::string& characterName, unsigned int level) : Warrior() {
    name = characterName;
    while (lvl < level) LvlUp();
}

void Warrior::Create() {
    std::cout << "Вы создали воина\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    GetWeapon();
}

void Warrior::GetInfo() const {
    NPC::GetInfo();
    std::cout << "Сила: " << strenght << '\n';
}

void Warrior::GetWeapon() {
    if (weapons.empty()) weapons.push_back({"Кулаки", 1});
    std::cout << name << " взял в руки оружие " << weapons.front().name << '\n'
              << "Добавка к урону = " << weapons.front().damage << '\n';
}

void Warrior::Recalculate() {
    const auto increase = static_cast<unsigned int>(1 + lvl * strenght * 0.1);
    damage += increase;
    health += increase;
    armor += increase;
}

Warrior::~Warrior() {
    std::cout << name << " пал смертью храбрых\n";
}
