#pragma once
#include <string>

class NPC {
protected:
    std::string className{"Персонаж"};
    std::string name{"npc"};
    unsigned int damage{2};
    unsigned int health{10};
    short lvl{1};
    unsigned int armor{5};

private:
    bool isEnemy{true};

public:
    unsigned int GetDamage() const;
    unsigned int GetHealth() const;
    void SetHealth(unsigned int value);
    virtual void GetInfo() const;
    virtual void Create();
    void LvlUp();
    virtual void Recalculate();

    friend void TakeDamage(NPC* npc, unsigned int damage);
    virtual ~NPC() = default;
};

void TakeDamage(NPC* npc, unsigned int damage);
