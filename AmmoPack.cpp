#include "AmmoPack.h"
#include "Hunter.h"
#include "Manager.h"

AmmoPack::AmmoPack(int frameWidth, int frameHeight, int x, int y) : Consumable(frameWidth,frameHeight,x,y)
{
	_name = "AmmoPack";
	_amount = 2 + rand() % ((5 + 1) - 2);
}

void AmmoPack::interact(IFigure* object)
{
	Hunter* hunter = dynamic_cast<Hunter*>(object);
	if (hunter) {
		hunter->addAmmo(_amount);
		
	}
	manager->remove(this);
}

