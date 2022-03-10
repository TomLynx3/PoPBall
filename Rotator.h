#pragma once

#define _USE_MATH_DEFINES
#include "Mover.h"
#include <cmath>

class Rotator :
    public Mover
{
public:
    Rotator(int frameWidth, int frameHeight, int x, int y);
    void move();
protected:
    float _alpha;
    float _dAlpha;

};

