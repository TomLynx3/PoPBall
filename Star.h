#pragma once
#include "Rotator.h"
class Star :
    public Rotator
{
public:
    Star(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics);
    void interactReaction() override;
};

