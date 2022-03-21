#pragma once
#include "Mover.h"
#include <string>
#include "Pictures.h"

using namespace std;
class GameCreature :
    public Mover
{
public:
    GameCreature(int frameWidth, int frameHeight, int x, int y,string name);
    const void draw(Graphics^ graphics) override;
    const bool interactable(IFigure* object) override;
    void interact(IFigure* object) override;
    void animate() override;
    void getDamaged(int dmg);
    const int getArmor();
    const float getHpInPercentages();
    const int getAmmoAmount();
    const int getAmmoLabelColor();
    const int getHpLabelColor();
    const int getDmg();
    const Coordinates getCenterPosition() override;
    
    
protected:
    int _currentImageIndex;
    int _lastImageIndex;
    int _dmg;
    int _armor;
    float _hp;
    float _maxHP;
    int _ammo;
    CreatureState _state;
    string _name;
    void _setState(CreatureState state);
    void _drawHpBar(Graphics^ g);
protected:
    bool _isHurt = false;
    bool _isDying = false;
};

