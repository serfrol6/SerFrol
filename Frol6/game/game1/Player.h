#pragma once
#include "NPC.h"
#include <memory>

class Player {
private:
    std::unique_ptr<NPC> currentCharacter;

public:
    void Create(std::unique_ptr<NPC> character);
    NPC* GetCharacter() const;
};
