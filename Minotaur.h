#pragma once
#include "GameCreature.h"
class Minotaur :
    public GameCreature
{
public:
    Minotaur(int frameWidth, int frameHeight, int x, int y, string name);
    void move() override;
    void doCommand(Command cmd) override;
    void makeReaction() override;
    bool canMakeAttack();
private:
    void _onDie();
    int _cooldown;
    bool _isAttackReady = true;
};

