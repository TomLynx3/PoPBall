#include "Triangle.h"

Triangle::Triangle(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 30;
}

const void Triangle::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));

	array<Point>^ points = gcnew array<Point>(3);

	Coordinates center = getCenterPosition();

	for (int i = 0; i < 3; i++) {
		points[i] = Point(
			center.x + _size * cos(_alpha + 2 * M_PI / 3 * i),
			center.y + _size * sin(_alpha + 2 * M_PI / 3 * i)
		);
	}

	graphics->FillPolygon(%brush, points);
}

void Triangle::setSpeed(float dX, float dY)
{
	if (dX == 0 && dY == 0) {
		_alpha = 0;
	}

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

void Triangle::interactReaction()
{
	setRandomColor();
}


