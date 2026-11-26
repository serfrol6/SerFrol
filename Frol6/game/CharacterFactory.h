#pragma once
#include "PlayerClass.h"
#include "NPC.h"
#include <memory>

std::unique_ptr<NPC> CreateCharacter(PlayerClass playerClass);
