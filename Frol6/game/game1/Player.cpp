#include "Player.h"
#include <utility>

void Player::Create(std::unique_ptr<NPC> character) {
    currentCharacter = std::move(character);
    if (currentCharacter) currentCharacter->Create();
}

NPC* Player::GetCharacter() const {
    return currentCharacter.get();
}
