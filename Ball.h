#pragma once
#include "IShape.h"

class Ball :
    public IShape
{
public:
    Ball(ShapeInitParams params);
    void Draw(Graphics^ graphics) override;
};

extern Ball* ball;