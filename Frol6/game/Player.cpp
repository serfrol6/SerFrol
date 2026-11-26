#include "Player.h"
#include <iostream>
#include <utility>

void Player::Create(std::unique_ptr<NPC> player)
{
    currentCharacter = std::move(player);
    if (currentCharacter) currentCharacter->Create();
}
NPC* Player::GetCharacter()
{
    return currentCharacter.get();
}
