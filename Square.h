#pragma once
#include "Rotator.h"
class Square :
    public Rotator
{
public:
    Square(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics);
    void interactReaction() override;
};

