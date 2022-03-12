#include "Explosion.h"


Explosion::Explosion(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth,frameHeight)
{
    _x = x;
    _y = y;
}

const bool Explosion::interactable(IFigure* object)
{
    return false;
}

const void Explosion::draw(Graphics^ graphics)
{
    

    int particleAmount = getCurrentParticleAmount();

    Coordinates center = getCenterPosition();


    for (int i = 0; i < particleAmount; i++) {

       

        double m = (1.0 / (RAND_MAX + 1.0) * ((double)(rand())));
        double l = (1.0 / (RAND_MAX + 1.0) * ((double)(rand())));
       
        float r = _explosionSize * sqrt(m);
        float theta = l * 2 *M_PI;

        float x = center.x + r * cos(theta);
        float y = center.y + r * sin(theta);

       drawParticle(graphics, Coordinates{x,y});
    }
}

void Explosion::move()
{

    if (_explosionSize == 100) {
        
        manager->remove(this);
        return;
    }

    _explosionSize += 1;
    _explosionDensity -= 0.05;
    
}


int Explosion::getCurrentParticleAmount()
{
    int area = M_PI *(_explosionSize * _explosionSize);


    return (area / _particleSize) * _explosionDensity;
}

const void Explosion::drawParticle(Graphics^ grp,Coordinates coord)
{
    SolidBrush brush(Color::FromArgb(getRandomExplosionColor()));
    
    array<Point>^ points = gcnew array<Point>(4);

    double theta = -M_PI / 2;
    double dtheta = 4 * M_PI / 4;

    for (int i = 0; i < 4; i++) {
        points[i] = Point(
            coord.x + _particleSize * cos(2 * M_PI / 4 * i),
            coord.y + _particleSize * sin(2 * M_PI / 4 * i)
        );

        theta += dtheta;
    }

    grp->FillPolygon(% brush, points);


}

const int Explosion::getRandomExplosionColor()
{
    switch (rand() & 3) {
    case ExplosionColors::RED:
        return Color::FromArgb(255,0,0).ToArgb();
    case ExplosionColors::YELLOW:
        return Color::FromArgb(255, 255, 0).ToArgb();
    case ExplosionColors::GREEN:
        return Color::FromArgb(173, 255, 47).ToArgb();
    }
}

void Explosion::makeReaction()
{
}
