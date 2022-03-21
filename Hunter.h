#pragma once
#define _USE_MATH_DEFINES
#include "GameCreature.h"
#include "Vector2.h"
class Hunter :
    public GameCreature
{
public:
    Hunter(int frameWidth, int frameHeight, int x, int y, string name);
    void move() override;
    void doCommand(Command cmd) override;
    const void draw(Graphics^ graphics) override;
    void interact(IFigure* object) override;
    void addAmmo(int amount);
    void addHp(int amount);
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
    
   
private:
    float _getRotationAngle(Point pt);
    const Vector2 _getVectorToCursor(int speedAcceleration);
    void _onDie();
    

};

