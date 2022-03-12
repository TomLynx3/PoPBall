#pragma once
#define _USE_MATH_DEFINES
#include "Mover.h"
#include <cmath>
#include "Manager.h"


enum ExplosionColors {RED,YELLOW,GREEN};
class Explosion :
    public Mover
{
public:
    Explosion(int frameWidth, int frameHeight, int x, int y);
    const bool interactable(IFigure* object);
    const void draw(Graphics^ graphics) override;
    void move() override;
private:
    int _explosionSize = 20;
    double _explosionDensity = 1;
    int _particleSize = 4;
    int getCurrentParticleAmount();
    const void drawParticle(Graphics^ grp,Coordinates coord);
    const int getRandomExplosionColor();
    void makeReaction() override;
};
