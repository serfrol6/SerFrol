#include "NPC.h"
#include <iostream>

unsigned int NPC::GetDamage() const { return damage; }
unsigned int NPC::GetHealth() const { return health; }

void NPC::SetHealth(unsigned int value) { health = value; }

void NPC::GetInfo() const {
    std::cout << "Имя: " << name << '\n'
              << "Здоровье: " << health << '\n'
              << "Урон: " << damage << '\n'
              << "Уровень: " << lvl << '\n'
              << "Броня: " << armor << '\n';
}

void NPC::Create() {}

void NPC::LvlUp() {
    ++lvl;
    std::cout << name << " повысил уровень персонажа\n";
    Recalculate();
}

void NPC::Recalculate() {
    damage += static_cast<unsigned int>(1 + lvl * 0.1);
    health += static_cast<unsigned int>(1 + lvl * 0.1);
    armor += static_cast<unsigned int>(1 + lvl * 0.1);
}

void TakeDamage(NPC* npc, unsigned int value) {
    if (npc == nullptr) {
        std::cout << "Персонаж не выбран.\n";
        return;
    }

    // Учитываем броню: урон не может быть отрицательным.
    const unsigned int actualDamage = value > npc->armor ? value - npc->armor : 0;
    npc->health = actualDamage >= npc->health ? 0 : npc->health - actualDamage;
    std::cout << "Получено " << actualDamage
              << " ед. урона. Текущее здоровье = " << npc->health << '\n';
}
