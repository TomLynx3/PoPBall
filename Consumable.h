#pragma once
#include "Mover.h"
#include <string>
using namespace std;

class Consumable :
    public Mover
{
public:
    Consumable(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics) override;
    void move() override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
protected:
    string _name;
};

