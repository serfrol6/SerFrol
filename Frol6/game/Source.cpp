//#define NOMINMAX
//#include <Windows.h>

#include <iostream>
#include <limits>
#include <clocale>
#include "NPC.h"
#include "Player.h"
#include "PlayerClass.h"
#include "GameState.h"
#include "CharacterFactory.h"

using namespace std;

int main()
{
    //SetConsoleCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);
    //setlocale(LC_ALL, ".UTF8");
    setlocale(LC_ALL, "Ru");
    
    Player player;
    GameState state = GameState::CharacterCreation;
    PlayerClass selectedClass = PlayerClass::Warrior;

    while (state != GameState::Exit)
    {
        switch (state)
        {
        case GameState::CharacterCreation:
        {
            cout << "Приветствую, путник! Присядь у костра да расскажи, кто ты." << endl;
            cout << "1 - воин\n2 - маг\n3 - паладин\n";
            int choice;
            if (!(cin >> choice))
            {
                cout << "Нужно ввести число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            if (choice < 1 || choice > 3)
            {
                cout << "Такого героя нет. Попробуй ещё раз." << endl;
                break;
            }
            selectedClass = static_cast<PlayerClass>(choice);
            auto character = CreateCharacter(selectedClass);
            if (!character)
            {
                cout << "Не удалось создать персонажа." << endl;
                break;
            }
            player.Create(std::move(character));
            state = GameState::MainMenu;
            break;
        }
        case GameState::MainMenu:
        {
            cout << "\n=== Главное меню ===\n";
            cout << "1 - сюжет\n2 - характеристики\n3 - выход\n";
            int choice;
            if (!(cin >> choice))
            {
                cout << "Нужно ввести число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            if (choice == 1) state = GameState::Story;
            else if (choice == 2) state = GameState::CharacterInfo;
            else if (choice == 3) state = GameState::Exit;
            else cout << "Такого пункта нет. Выбери 1, 2 или 3." << endl;
            break;
        }
        case GameState::Story:
            cout << "\nУ тракта пропал караван. Следы ведут в сторону старых руин..." << endl;
            state = GameState::MainMenu;
            break;
        case GameState::CharacterInfo:
            if (player.GetCharacter() != nullptr)
                player.GetCharacter()->GetInfo();
            else
                cout << "Персонаж ещё не создан." << endl;
            state = GameState::MainMenu;
            break;
        case GameState::Exit:
            break;
        }
    }
    cout << "До новых встреч, путник!" << endl;
    return 0;
}
