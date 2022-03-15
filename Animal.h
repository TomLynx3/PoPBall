#pragma once
#include "Mover.h"
#include "Pictures.h"
class Animal :
    public Mover
{
public:
    Animal(int frameWidth, int frameHeight, int x, int y);
    const void draw(Graphics^ graphics) override;
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
    void animate() override;
private:
    int _currentImageIndex;
};

