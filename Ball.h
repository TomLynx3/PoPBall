#pragma once
#include "Mover.h"


class Ball :
    public Mover
{
public:
    Ball(int frameHeight, int frameWidth);
    const void draw(Graphics^ graphics) override;
    void interactReaction() override;
};
