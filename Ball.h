#pragma once
#include "IShape.h"
#include "Vector2.h"

class Ball :
    public IShape
{
public:
    Ball(ShapeInitParams params);
    void draw(Graphics^ graphics) override;
    void interact(IShape* object) override;
};
