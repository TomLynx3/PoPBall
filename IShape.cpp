#include "IShape.h"

IShape::IShape(ShapeInitParams params)
{
	_x = params.x;
	_y = params.y;
	_size = params.size;
	_color = params.color;
	_frameWidth = params.frameWidth;
	_frameHeight = params.frameHeight;
	_dx = params.dx;
	_dy = params.dy;
	
}

void IShape::setPos(int x, int y)
{

	if (_size < x && x < (_frameWidth - _size)) {
		_x=x;
	}

	if (_size < y && y < (_frameHeight - _size)) {
		_y =y;
	}
}

int IShape::getColor()
{
	return _color;
}

void IShape::setColor(int color)
{
	_color = color;
}

int IShape::getSize()
{
	return _size;
}

void IShape::setSize(int size)
{
	if (size <= 1 || size >=100) {
		return;
	}

	if (checkColisionWithWall(Side::W)) {
		_x += 5;
	}

	if (checkColisionWithWall(Side::E)) {
		_x -= 5;
	}

	if (checkColisionWithWall(Side::N)) {
		_y += 5;
	}

	if (checkColisionWithWall(Side::S)) {
		_y -= 5;
	}

	_size = size;
}

void IShape::setRandomColor()
{
	setColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
}

float IShape::getdX()
{
	return _dx;
}

float IShape::getdY()
{
	return _dy;
}

void IShape::setSpeed(float dX, float dY)
{
	
	if (dX > 15) {
		dX = 15;
	}

	if (dX < -15) {
		dX = -15;
	}

	if (dY> 15) {
		dY = 15;
	}

	if (dY < -15) {
		dY = -15;
	}

	_dx = dX;
	_dy = dY;
}

void IShape::move()
{
	
	if (checkColisionWithWall(Side::W) || checkColisionWithWall(Side::E)) {
		_dx = -_dx;
	}

	if (checkColisionWithWall(Side::N) || checkColisionWithWall(Side::S)) {
		_dy = -_dy;
	}

	_x += _dx;
	_y += _dy;
}

void IShape::followTo(int x, int y)
{
	float deltaX = x - _x;
	float deltaY = y - _y;

	float angle = atan2(fabs(deltaY),fabs(deltaX));

	float speed = getCurrentSpeed();

	float dx = speed * cos(angle);
	
	float dy = speed * sin(angle);

	_dx = x < _x ? -dx : dx;
	
	_dy = y < _y ? -dy : dy;

}

bool IShape::checkColisionWithWall(Side side)
{
	switch(side) {
	case Side::W:
		return (_x - _size - 5 <= 0);
	case Side::E:
		return (_x + _size + 5) >= _frameWidth;
	case Side::N:
		return (_y - _size - 5 <= 0);
	case Side::S:
		return (_y + _size + 5) >= _frameHeight;
	}
	return false;
}

float IShape::getCurrentSpeed()
{
	return sqrt(pow(_dx,2) + pow(_dy,2));
}


