#include "Warrior.h"
#include <iostream>
#include <utility>

Warrior::Warrior()
{
    damage = 20;
    health = 30;
    armor = 15;
}
Warrior::Warrior(std::string name, unsigned int lvl)
{
    this->name = std::move(name);
    for (unsigned int i = 1; i < lvl; ++i) LvlUp();
    this->lvl = static_cast<short>(lvl);
}
void Warrior::Create()
{
    std::cout << "Вы создали воина\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    GetWeapon();
}
void Warrior::GetInfo()
{
    NPC::GetInfo();
    std::cout << "Сила " << strenght << std::endl;
}
void Warrior::GetWeapon()
{
    Weapon weapon;
    weapon.damage = 1;
    weapon.name = "Кулаки";
    weapons.push_back(weapon);
    std::cout << name << " взял в руки оружие " << weapons[0].name << std::endl;
    std::cout << "Добавка к урону = " << weapons[0].damage << std::endl;
}
void Warrior::Recalculate()
{
    damage += static_cast<unsigned int>(1 + lvl * strenght * 0.1);
    health += static_cast<unsigned int>(1 + lvl * strenght * 0.1);
    armor += static_cast<unsigned int>(1 + lvl * strenght * 0.1);
}
Warrior::~Warrior()
{
    std::cout << name << " пал смертью храбрых" << std::endl;
}
