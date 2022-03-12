#pragma once
#include "Rotator.h"
#define MAX_COUNT 7
#include "Manager.h"
#include "Explosion.h"
class Square :
    public Rotator
{
public:
    Square(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics);
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
};

