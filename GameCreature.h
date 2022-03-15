#pragma once
#include "Mover.h"
#include "Pictures.h"
#include "StateQueue.h"
#include <string>

using namespace std;

class GameCreature :
    public Mover
{
public:
    GameCreature(int frameWidth, int frameHeight, int x, int y,string name);
    const void draw(Graphics^ graphics) override;
    void interact(IFigure* object) override;
    const bool interactable(IFigure* object) override;
    void makeReaction() override;
    void animate() override;
protected:
    int _currentImageIndex;
    int _lastImageIndex;
    CreatureState _state;
    string _name;
    void _setState(CreatureState state);

private:
    bool _stateChangeRequested = false;
  /*  CreatureState _stateQueue[STATE_QUEUE_LENGTH];
    CreatureState _stateToChange;*/
    StateQueue _stateQueue;
};

