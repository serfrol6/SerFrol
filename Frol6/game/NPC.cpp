#include"NPC.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory>

using namespace std;
unsigned int NPC::GetDamage() //геттер
{
    return damage;
};
unsigned int NPC::GetHealth()
{
    return health;
};
void NPC::SetHealth(unsigned int health) //сеттер
{
    this->health = health;
};
 void NPC::GetInfo()
{
    cout << "Имя: " << name << endl;
    cout << "Здоровье: " << health << endl;
    cout << "Урон: " << damage << endl;
    cout << "Уровень: " << lvl << endl;
    cout << "Броня: " << armor << endl;
};

 void NPC::Create() //создать нпс нельзя поэтому он виртуальный и весь класс тоже
{

};
void NPC::LvlUp()
{
    lvl += 1;
    cout << name << " повысил уровень персонажа " << endl;
    Recalculate();
};
void NPC::Recalculate() // кастомизировать для война и вошебника зависимости от интеллекта/силы
{
    damage += (1 + lvl * 0.1);
    health += (1 + lvl * 0.1);
    armor += (1 + lvl * 0.1);
};
void TakeDamage(NPC* npc, unsigned int damage)
{
    npc->health -= damage;
    cout << "Вы получили " << damage << " едениц урона ";
    cout << " Текущее здоровье = " << npc->health;
}