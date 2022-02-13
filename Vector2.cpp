#include "Vector2.h"


Vector2::Vector2(float x, float y)
{
	_x = x;
	_y = y;
}

float Vector2::getX()
{
	return _x;
}

float Vector2::getY()
{
	return _y;
}

float Vector2::norm()
{
	return sqrt(pow(_x, 2) + pow(_y, 2));
}

void Vector2::multiple(float number)
{
	_x =_x* number;
	_y =_y* number;
}

Vector2 Vector2::add(Vector2 vector)
{
	int x = _x + vector.getX();
	int y = _y + vector.getY();

	return Vector2(x,y);
}

Vector2 Vector2::substract(Vector2 vector)
{
	int x = _x - vector.getX();
	int y = _y - vector.getY();

	return Vector2(x,y);
}


