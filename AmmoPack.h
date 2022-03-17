#pragma once
#include "Consumable.h"
class AmmoPack :
    public Consumable
{
public:
    AmmoPack(int frameWidth, int frameHeight, int x, int y);
    void interact(IFigure* object) override;
private:
    int _amount;
};

