#pragma once
#include "Mover.h"
#include <string>
using namespace std;

class Obstacle :
    public Mover
{
public:
    Obstacle(int frameWidth, int frameHeight, int x, int y,string name);
    const bool interactable(IFigure* object);
    const void draw(Graphics^ graphics) override;
    void move() override;
    void makeReaction() override;
    const Coordinates getCenterPosition() override;
private:
    string _name;
};

