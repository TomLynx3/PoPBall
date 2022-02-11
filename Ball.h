#pragma once
#include "IShape.h"

class Ball :
    public IShape
{
public:
    Ball(int frameWidth,int frameHeight);
    void Draw(Graphics^ graphics) override;
};

extern Ball* ball;