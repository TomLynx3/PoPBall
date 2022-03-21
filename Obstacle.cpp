#include "Obstacle.h"
#include "Pictures.h"
#include "GameCreature.h"
#include "Bullet.h"


Obstacle::Obstacle(int frameWidth, int frameHeight, int x, int y,string name) : Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_dx = 0;
	_dy = 0;
	_name = name;
	_size = 45;
}

const bool Obstacle::interactable(IFigure* object)
{
	GameCreature* obj = dynamic_cast<GameCreature*>(object);
	Bullet* bullet = dynamic_cast<Bullet* > (object);

	return obj != NULL || bullet != NULL;
}

const void Obstacle::draw(Graphics^ graphics)
{

	Bitmap^ img = Pictures::getAssetByName(gcnew String(_name.c_str()));

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));

	graphics->DrawImage(img, displayRectangle);

}

void Obstacle::move()
{
	_dx = 0;
	_dy = 0;
}

void Obstacle::makeReaction()
{
}

const Coordinates Obstacle::getCenterPosition()
{
	return Coordinates{_x, _y};
}
