#pragma once
#include "Mover.h"
#include "Manager.h"
class Bullet :
    public Mover
{
public:
    Bullet(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics) override;
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
    void move() override;
private:
    int _reboundTimesLeft = 2;
};

