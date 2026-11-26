#include <iostream>
#include <memory>
#include <windows.h>
    
#include "Evil.h"
#include "NPC.h"
#include "Paladin.h"
#include "Player.h"
#include "Warrior.h"
#include "Wizard.h"

// Перечисление типов персонажей.
enum class CharacterType {
    Warrior = 1,
    Wizard,
    Paladin
};

// Перечисление качества оружия.
enum class WeaponQuality {
    Common = 1,
    Uncommon,
    Rare,
    Epic,
    Legendary
};

int main() {
    //setlocale(LC_ALL, "Ru");
    SetConsoleCP(CP_UTF8);          // кодировка для ввода
    SetConsoleOutputCP(CP_UTF8);
    
    // Злодей создаётся программой, а не игроком.
    Evil dragon("Дракон");
    Player player;

    std::cout << "Приветствую, путник! Присядь у костра да расскажи, кто ты.\n"
                 "\t1 - воин\n\t2 - маг\n\t3 - паладин\n";
    int characterChoice = 0;
    if (!(std::cin >> characterChoice)) return 1;

    CharacterType character;
    switch (characterChoice) {
    case 1:
        character = CharacterType::Warrior;
        player.Create(std::make_unique<Warrior>());
        break;
    case 2:
        character = CharacterType::Wizard;
        player.Create(std::make_unique<Wizard>());
        break;
    case 3:
        character = CharacterType::Paladin;
        player.Create(std::make_unique<Paladin>());
        break;
    default:
        std::cout << "Такого героя еще не было в наших краях.\n";
        return 0;
    }

    std::cout << "\nВыберите качество оружия:\n"
                 "1 - обычное\n2 - необычное\n3 - редкое\n"
                 "4 - эпическое\n5 - легендарное\n";
    int weaponChoice = 0;
    if (!(std::cin >> weaponChoice)) return 1;

    WeaponQuality quality;
    switch (weaponChoice) {
    case 1:
        quality = WeaponQuality::Common;
        std::cout << "Обычное оружие: без особых свойств.\n";
        break;
    case 2:
        quality = WeaponQuality::Uncommon;
        std::cout << "Необычное оружие: немного лучше обычного.\n";
        break;
    case 3:
        quality = WeaponQuality::Rare;
        std::cout << "Редкое оружие: хорошая находка.\n";
        break;
    case 4:
        quality = WeaponQuality::Epic;
        std::cout << "Эпическое оружие: очень мощное.\n";
        break;
    case 5:
        quality = WeaponQuality::Legendary;
        std::cout << "Легендарное оружие: оружие высшего качества.\n";
        break;
    default:
        std::cout << "Неверный номер качества оружия.\n";
        return 0;
    }

    std::cout << "Числовое значение выбранного персонажа: "
              << static_cast<int>(character) << '\n';
    std::cout << "Числовое значение качества оружия: "
              << static_cast<int>(quality) << '\n';

    TakeDamage(player.GetCharacter(), 5);
    std::cout << '\n';
    return 0;
}
