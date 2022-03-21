#include "Bullet.h"
#include "GameCreature.h"
#include "Obstacle.h";

Bullet::Bullet(int frameWidth, int frameHeight, int x, int y,int dmg) : Mover(frameWidth, frameHeight)
{
	_x = x;
	_y = y;
	_size = 2;
	_dmg = dmg;
	_color = Color::Black.ToArgb();
}

const void Bullet::draw(Graphics^ graphics)
{

	

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));


	SolidBrush brush(Color::FromArgb(_color));

	graphics->FillEllipse(% brush, displayRectangle);
}

void Bullet::interact(IFigure* object)
{
	GameCreature* creature = dynamic_cast<GameCreature*>(object);
	Obstacle* obstacle = dynamic_cast<Obstacle*>(object);
	

	if (creature) {
		creature->getDamaged(_dmg);
		manager->remove(this);
	}
	else if (obstacle) {

		_dx = -_dx;
		_dy = _dy;
		_reboundTimesLeft--;
		_dmg--;
	}
	
	

}

const bool Bullet::interactable(IFigure* object)
{
	GameCreature* gameCreature = dynamic_cast<GameCreature*>(object);
	Obstacle* obstacle = dynamic_cast<Obstacle*>(object);
	return gameCreature != NULL || obstacle != NULL;

}

void Bullet::makeReaction()
{
}

void Bullet::move()
{
	if (checkColisionWithWall(Side::W) || checkColisionWithWall(Side::E)) {
		_dx = -_dx;
		_reboundTimesLeft--;
		_dmg--;
	}

	if (checkColisionWithWall(Side::N) || checkColisionWithWall(Side::S)) {
		_dy = -_dy;
		_reboundTimesLeft--;
		_dmg--;
	}

	if (_reboundTimesLeft == 0) {
		return manager->remove(this);
	}

	_x += _dx;
	_y += _dy;

	
}

const int Bullet::getDmg()
{
	return _dmg;
}


