#include "Consumable.h"
#include "Pictures.h"
#include "Hunter.h"

Consumable::Consumable(int frameWidth, int frameHeight, int x, int y):Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_size = 35;
}

const void Consumable::draw(Graphics^ graphics)
{
	Bitmap^ img = Pictures::getAssetByName(gcnew String(_name.c_str()));

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size, _size));

	graphics->DrawImage(img,displayRectangle);
}

void Consumable::move()
{
	_dx = 0;
	_dy = 0;
}

const bool Consumable::interactable(IFigure* object)
{
	Hunter* hunter = dynamic_cast<Hunter*>(object);
	return hunter != NULL;
}

void Consumable::makeReaction()
{
}

