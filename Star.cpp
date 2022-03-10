#include "Star.h"

Star::Star(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 20;
}

const void Star::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));

	array<Point>^ points = gcnew array<Point>(5);

	Coordinates center = getCenterPosition();

	double theta = -M_PI / 2;
	double dtheta = 4 * M_PI / 5;
	
	for (int i = 0; i < 5; i++) {
		points[i] = Point(
			center.x + _size * cos(_alpha + theta),
			center.y + _size * sin(_alpha + theta)
		);

		theta += dtheta;
	}



	graphics->FillPolygon(% brush, points);
}

void Star::interactReaction()
{
	_dAlpha = (2 * M_PI) / 100 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (((2 * M_PI) / 30) - ((2 * M_PI) / 100))));
}
