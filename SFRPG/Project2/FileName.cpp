#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory>

// Ключевые понятия принципы ООП:
// 1) Наследование
// 2) Полиморфизм
// 3) Абстракция
// 4) Инкапсуляция (геттер и сеттер)

// Модификаторы доступа:
// public - публичный (Доступен внутри класса, внутри наследника и в основом потоке программы)
// protected - защищенный (Можно изменять в исходном классе и в наследнике)
// private - приватный (Доступен только в исзодном классе) |НЕ НАСЛЕДУЕТСЯ|

using namespace std;

struct Weapon
{
    string name{ "weapon" };
    unsigned int damage{ 1 };
};

struct Spell
{
    string name{ "spell" };
    unsigned int damage{ 1 };
};

class NPC
{
protected:
    string name{ "npc" };
    unsigned int damage{ 2 };
    unsigned int health{ 10 };
    short lvl = 1;
    unsigned int armor = 5;

private:
    bool isEnemy = true;

public:
    unsigned int GetDamage() //геттер
    {
        return damage;
    };
    unsigned int GetHealth()
    {
        return health;
    };
    void SetHealth(unsigned int health) //сеттер
    {
        this->health = health;
    };
    virtual void GetInfo()
    {
        cout << "Имя: " << name << endl;
        cout << "Здоровье: " << health << endl;
        cout << "Урон: " << damage << endl;
        cout << "Уровень: " << lvl << endl;
        cout << "Броня: " << armor << endl;
    };

    virtual void Create() //создать нпс нельзя поэтому он виртуальный и весь класс тоже
    {

    };
    void LvlUp()
    {
        lvl += 1;
        cout << name << " повысил уровень персонажа " << endl;
        Recalculate();
    };
    void Recalculate() // кастомизировать для война и вошебника зависимости от интеллекта/силы
    {
        damage += (1 + lvl * 0.1);
        health += (1 + lvl * 0.1);
        armor += (1 + lvl * 0.1);
    };

    friend void TakeDamage(NPC*, unsigned int damage);

    virtual ~NPC() = default;
};

class Warrior : virtual public NPC
{
protected:
    short strenght{ 21 };
    vector<Weapon> weapons;

public:
    // Конструктор по умолчанию
    Warrior()
    {
        // cout << "конструктор воин" << endl;
        damage = 20;
        health = 30;
        armor = 15;
    };
    Warrior(string name, unsigned int lvl = 1)
    {
        this->name = name; // такой способ задания уместен только для сеттер
        for (size_t i = 0; i < lvl - 1; i++)
        {
            LvlUp();
        }
        this->lvl = lvl; // this - указывает на конкретный экземпляр класса, в котором вызывается конструктор
    };
    void Create() override
    {
        cout << "Вы создали война\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        GetWeapon();
    };
    void GetInfo() override
    {
        NPC::GetInfo();
        cout << "Сила " << strenght << endl;
    };
    void GetWeapon()
    {
        Weapon weapon;
        weapon.damage = 1;
        weapon.name = "Кулаки";
        weapons.push_back(weapon);

        cout << name << " взял в руки оружие " << weapons[0].name << endl;
        cout << "Добавка к урона = " << weapons[0].damage << endl;
    };
    void Recalculate()
    {
        damage += (1 + lvl * strenght * 0.1);
        health += (1 + lvl * strenght * 0.1);
        armor += (1 + lvl * strenght * 0.1);
    }
    ~Warrior()
    {
        cout << name << " пал смертью храбрых" << endl;
    }
};

class Wizard : virtual public NPC
{
protected:
    short intellect{ 29 };
    vector<Spell> spells;

public:
    Wizard()
    {
        // cout << "конструктор волшебник" << endl;
        damage = 27;
        health = 21;
        armor = 10;
    };
    Wizard(string name, unsigned int lvl = 1)
    {
        this->name = name;
        for (size_t i = 0; i < lvl - 1; i++)
        {
            LvlUp();
        }
        this->lvl = lvl;
    };
    //Реализуйте это в нпс (хрнаить название класса в поле)
    void Create() override
    {
        cout << "Вы создали Мага\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        LearnSpell();
    };
    void GetInfo() override
    {
        NPC::GetInfo();
        cout << "Интеллект: " << intellect << endl;
    };
    void LearnSpell()
    {
        Spell spell;
        spell.damage = 1;
        spell.name = "Вспышка";
        spells.push_back(spell);

        cout << name << " Изучил заклинение " << spells[0].name << endl;
        cout << "Добавка к урона = " << spells[0].damage << endl;
    };
    void Recalculate()
    {
        damage += (1 + lvl * intellect * 0.1);
        health += (1 + lvl * intellect * 0.1);
        armor += (1 + lvl * intellect * 0.1);
    }
    ~Wizard()
    {
        cout << name << " испускает дух" << endl;
    }
};

class Evil : public NPC
{
public:
    Evil()
    {
        name = "Злодей";
        health = 10;
        damage = 5;
        armor = 3;
    }
    Evil(string name) : Evil()
    {
        this->name = name;
    };
    Evil(string name, unsigned int damage) : Evil(name)
    {
        this->damage = damage;
    };
    Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
    {
        this->health = health;
    };
    Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
    {
        this->armor = armor;
    };
    ~Evil()
    {
        cout << name << " сгинул в пучине адского пламени" << endl;
    }
};

//Множественное наследование
class Paladin : public Warrior, public Wizard
{
public:
    Paladin()
    {
        intellect = 25;
        strenght = 19;
        health = 25;
        damage = 25;
    };
    void Create() override
    {
        cout << "Вы создали Паладина\nЗадайте имя игрока\n";
        cin >> name;

        GetInfo();
        LearnSpell();
        GetWeapon();
    };
    void GetInfo() override
    {
        NPC::GetInfo();
        cout << "Сила: " << strenght << endl;
        cout << "Интеллект: " << intellect << endl;
    };
    ~Paladin()
    {
        cout << "Отправляется к праотцам" << endl;
    }

};

class Player
{
private:
    unique_ptr<NPC>currentCharecter{ nullptr };
public:
    void Create(unique_ptr<NPC> character)
    {
        currentCharecter = move(character);
        currentCharecter->Create();
    };
    NPC* GetCharacter()
    {
        return currentCharecter.get();
    }
    void GetInfo()
    {
        currentCharecter->GetInfo();
    }
};

//можно использовать даже private поля класса NPC, так как функция TakeDamage является дружественной к классу NPC  (Нарушает инкапсуляцию, но иногда это необходимо)
void TakeDamage(NPC* npc, unsigned int damage)
{
    npc->SetHealth(npc->GetHealth() - damage);
    cout << npc->name << " получил урон " << damage << endl;
    cout << "Оставшееся здоровье =" << npc->GetHealth() << endl;

}
int main()
{
    setlocale(LC_ALL, "RUS");
    // Warrior *warrior1 = new Warrior("Друг война", 5); // как только создался экземпляр класса, сразу вызвался конструктор по умолчанию
    // warrior1->GetInfo();                              // стрека работает с указателями
    // // delete warrior1;                                  // удаляем экземпляр класса, вызывается деструктор
    // // warrior1 = nullptr;
    // cout << endl;
    // Wizard wizard1();
    Player player;
    cout << "Присядь путник у костра и расскажи кто ты" << endl;
    cout << "\t1 - воин\n\t2 - маг \n\t3 - паладин" << endl;
    short choise = 0;
    cin >> choise;
    switch (choise)
    {
    case 1:
        player.Create(make_unique<Warrior>());
        break;
    case 2:
        player.Create(make_unique<Wizard>());
        break;
    case 3:
        player.Create(make_unique<Paladin>());
        break;
    default:
        cout << "Таких героев еще не было в наших краях" << endl;
    }
    cout << endl;
    cout << "Информация о персонаже" << endl;
    player.GetInfo();

    // vector<unique_ptr<Evil>> evils;

    // evils.push_back(make_unique<Evil>());
    // evils.push_back(make_unique<Evil>());
    // evils.push_back(make_unique<Evil>("Кабанчик"));
    // evils.push_back(make_unique<Evil>("Гнолл", 12));
    // evils.push_back(make_unique<Evil>("Гнолл дробитель", 15, 20));
    // evils.push_back(make_unique<Evil>("Дракон", 50, 100, 200));

    // for (const auto &evil : evils)
    // {
    //     evil->GetInfo();
    //     cout << endl;
    // }

    return 0;
}