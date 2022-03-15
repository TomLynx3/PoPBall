#include "Bullet.h"

Bullet::Bullet(int frameWidth, int frameHeight, int x, int y) : Mover(frameWidth, frameHeight)
{
	_x = x;
	_y = y;
	_size = 2;
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
	
}

const bool Bullet::interactable(IFigure* object)
{
	return false;
}

void Bullet::makeReaction()
{
}

void Bullet::move()
{
	if (checkColisionWithWall(Side::W) || checkColisionWithWall(Side::E)) {
		_dx = -_dx;
		_reboundTimesLeft--;
	}

	if (checkColisionWithWall(Side::N) || checkColisionWithWall(Side::S)) {
		_dy = -_dy;
		_reboundTimesLeft--;
	}

	if (_reboundTimesLeft == 0) {
		return manager->remove(this);
	}

	_x += _dx;
	_y += _dy;

	
}
