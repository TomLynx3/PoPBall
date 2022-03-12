#pragma once
#include "Mover.h"
#define MAX_COUNT 5
#include "Manager.h"
#include "Explosion.h"

class Ball :
    public Mover
{
public:
    Ball(int frameHeight, int frameWidth);
    const void draw(Graphics^ graphics) override;
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;

};
