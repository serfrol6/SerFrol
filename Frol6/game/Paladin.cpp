#include "Paladin.h"
#include <iostream>

Paladin::Paladin()
{
    intellect = 25;
    strenght = 19;
    health = 25;
    damage = 25;
}
void Paladin::Create()
{
    std::cout << "Вы создали паладина\nЗадайте имя игрока\n";
    std::cin >> name;
    GetInfo();
    LearnSpell();
    GetWeapon();
}
void Paladin::GetInfo()
{
    NPC::GetInfo();
    std::cout << "Сила: " << strenght << std::endl;
    std::cout << "Интеллект: " << intellect << std::endl;
}
Paladin::~Paladin()
{
    std::cout << "Отправляется к праотцам" << std::endl;
}
