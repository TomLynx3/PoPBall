#pragma once
#define _USE_MATH_DEFINES
#include "GameCreature.h"

class Hunter :
    public GameCreature
{
public:
    Hunter(int frameWidth, int frameHeight, int x, int y, string name);
    void move() override;
    void doCommand(Command cmd) override;
    const void draw(Graphics^ graphics) override;
private:
    float _getRotationAngle(Point pt);
};

