#pragma once
#include "Rotator.h"
#define MAX_COUNT 5
#include "Manager.h"
#include "Explosion.h"
class Triangle :
    public Rotator
{
public:
    Triangle(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics);
    void setSpeed(float dX, float dY) override;
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
};

