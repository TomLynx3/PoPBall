#include "Mover.h"

Mover::Mover(int frameWidth, int frameHeight)
{
	_frameHeight = frameHeight;
	_frameWidth = frameWidth;
	_x = frameWidth/2;
	_y = frameHeight /2;
	_size = 15;
	_color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	_dx = rand() % 21 - 10;
	_dy = rand() % 21 - 10;

}

void Mover::setPos(int x, int y)
{

	if (_size < x && x < (_frameWidth - _size)) {
		_x = x;
	}

	if (_size < y && y < (_frameHeight - _size)) {
		_y = y;
	}
}

const int Mover::getColor()
{
	return _color;
}

void Mover::setColor(int color)
{
	_color = color;
}

const int Mover::getSize()
{
	return _size;
}

void Mover::setSize(int size)
{

	if (size <= 1 || size >= 100) {
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

void Mover::setRandomColor()
{
	setColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
}

const float Mover::getdX()
{
	return _dx;
}

const float Mover::getdY()
{
	return _dy;
}

void Mover::setSpeed(float dX, float dY)
{

	if (dX > 15) {
		dX = 15;
	}

	if (dX < -15) {
		dX = -15;
	}

	if (dY > 15) {
		dY = 15;
	}

	if (dY < -15) {
		dY = -15;
	}

	_dx = dX;
	_dy = dY;
}

void Mover::move()
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

void Mover::followTo(int x, int y)
{
	float deltaX = x - _x;
	float deltaY = y - _y;

	float angle = atan2(fabs(deltaY), fabs(deltaX));

	float speed = getCurrentSpeed();

	float dx = speed * cos(angle);

	float dy = speed * sin(angle);

	_dx = x < _x ? -dx : dx;

	_dy = y < _y ? -dy : dy;
}

const Coordinates Mover::getCenterPosition()
{
	Coordinates coord;

	coord.x = _x - _size;
	coord.y = _y - _size;

	return coord;
}

const Coordinates Mover::getPosition()
{
	return Coordinates{ _x,_y };
}

const float Mover::getCurrentSpeed()
{
	return sqrt(pow(_dx, 2) + pow(_dy, 2));
}

void Mover::interact(IFigure* object)
{

	Vector2 firstVelocityVector(_dx, _dy);
	Vector2 secondVelocityVector(object->getdX(), object->getdY());


	Coordinates objectCoord = object->getPosition();

	float alpha1 = atan2((objectCoord.y - _y), (objectCoord.x - _x));
	float beta1 = atan2(firstVelocityVector.getY(), firstVelocityVector.getX());
	float gamma1 = beta1 - alpha1;



	float decomp11 = firstVelocityVector.norm() * sin(gamma1);
	float decomp12 = firstVelocityVector.norm() * cos(gamma1);


	float alpha2 = atan2((_y - objectCoord.y), (_x - objectCoord.x));
	float beta2 = atan2(secondVelocityVector.getY(), secondVelocityVector.getX());
	float gamma2 = beta2 - alpha2;

	float decomp21 = secondVelocityVector.norm() * cos(gamma2);
	float decomp22 = secondVelocityVector.norm() * sin(gamma2);

	float subvector1 = ((_size - object->getSize()) * decomp12 - 2 * object->getSize() * decomp21) / (object->getSize() + _size);
	float subvector2 = ((_size - object->getSize()) * decomp21 + 2 * _size * decomp12) / (object->getSize() + _size);

	Vector2 v1(-sin(alpha1), cos(alpha1));
	Vector2 v2(-sin(alpha2), cos(alpha2));
	Vector2 v3(cos(alpha1), sin(alpha1));
	Vector2 v4(cos(alpha2), sin(alpha2));

	v1.multiple(decomp11);
	v3.multiple(subvector1);

	Vector2 newVec1 = v1.add(v3);

	v2.multiple(decomp22);
	v4.multiple(subvector2);

	Vector2 newVec2 = v2.substract(v4);


	_dx = newVec1.getX();
	_dy = newVec1.getY();

	object->setSpeed(newVec2.getX(), newVec2.getY());

	interactReaction();
	object->interactReaction();

}

const bool Mover::checkColisionWithWall(Side side)
{
	switch (side) {
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
