#pragma once
#include<string>

class NPC
{
protected:
    std::string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 10 };
    short lvl = 1;
    unsigned int armor = 5;

private:
    bool isEnemy = true;

public:
    unsigned int GetDamage();//геттер
   
    unsigned int GetHealth();
    void SetHealth(unsigned int health); //сеттер
    virtual void GetInfo();
   

    virtual void Create(); //создать нпс нельзя поэтому он виртуальный и весь класс тоже
    
    void LvlUp();
   
    void Recalculate(); // кастомизировать для война и вошебника зависимости от интеллекта/силы
    

    friend void TakeDamage(NPC* npc, unsigned int damage);

    virtual ~NPC() = default;
};