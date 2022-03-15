#pragma once
#include "GameCreature.h"
class Monster :
    public GameCreature
{
public:
    Monster(int frameWidth, int frameHeight, int x, int y, string name);
};

