#pragma once
#include "Consumable.h"
class LifePoints :
    public Consumable
{
public:
    LifePoints(int frameWidth, int frameHeight, int x, int y);
    void interact(IFigure* object) override;
private:
    int _amount;
};

