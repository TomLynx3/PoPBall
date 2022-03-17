#include "LifePoints.h"
#include "Hunter.h";
#include "Manager.h"

LifePoints::LifePoints(int frameWidth, int frameHeight, int x, int y) : Consumable(frameWidth,frameHeight,x,y)
{
	_name = "LifePoints";
	_amount = 2 + rand() % ((5 + 1) - 2);
}

void LifePoints::interact(IFigure* object)
{
	Hunter* hunter = dynamic_cast<Hunter*>(object);
	if (hunter) {
		hunter->addHp(_amount);
		
	}
	manager->remove(this);
}
