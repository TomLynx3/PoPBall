#pragma once
#include "Rotator.h"
class Triangle :
    public Rotator
{
public:
    Triangle(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics);
    void setSpeed(float dX, float dY) override;
    void interactReaction() override;
};

