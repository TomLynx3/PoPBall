#include "Square.h"

Square::Square(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 25;
}

const void Square::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));

	array<Point>^ points = gcnew array<Point>(4);

	Coordinates center = getCenterPosition();

	for (int i = 0; i < 4; i++) {
		points[i] = Point(
			center.x + _size * cos(_alpha + 2 * M_PI / 4 * i),
			center.y + _size * sin(_alpha + 2 * M_PI / 4 * i)
		);
	}

	graphics->FillPolygon(% brush, points);

}

void Square::interactReaction()
{
	_size = 10 + (rand() % 30);
}
