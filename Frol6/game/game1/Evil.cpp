#include "Evil.h"
#include <iostream>
#include <utility>

Evil::Evil() {
    className = "Злодей";
    name = "Злодей";
    health = 10;
    damage = 5;
    armor = 3;
}

Evil::Evil(std::string name) : Evil() {
    this->name = std::move(name);
}

Evil::Evil(std::string name, unsigned int damage) : Evil(std::move(name)) {
    this->damage = damage;
}

Evil::Evil(std::string name, unsigned int damage, unsigned int health)
    : Evil(std::move(name), damage) {
    this->health = health;
}

Evil::Evil(std::string name, unsigned int damage, unsigned int health, unsigned int armor)
    : Evil(std::move(name), damage, health) {
    this->armor = armor;
}

void Evil::Create() {
    // Злодей создаётся программой, а не игроком.
}

Evil::~Evil() {
    std::cout << name << " заточен в Черный дельфин\n";
}
