#include "Triangle.h"

Triangle::Triangle(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 30;
}

const void Triangle::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));
	Pen pen(Color::FromArgb(158, 50, 168), 5);

	array<Point>^ points = gcnew array<Point>(3);

	Coordinates center = getCenterPosition();

	for (int i = 0; i < 3; i++) {
		points[i] = Point(
			center.x + _size * cos(_alpha + 2 * M_PI / 3 * i),
			center.y + _size * sin(_alpha + 2 * M_PI / 3 * i)
		);
	}

	graphics->DrawPolygon(%pen, points);
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


void Triangle::interact(IFigure* object)
{
	Mover::interact(object);

	if (interactable(object)) {

		if (typeid(*object) == typeid(*this)) {


			if (rand() % 4 == 0 && manager->countOf(&typeid(*this)) < MAX_COUNT) {

				manager->place(new Triangle(_frameWidth, _frameHeight, 0, 0));
			}
		}
		else {
			if (rand() % 4 == 0) {

				manager->add(new Explosion(_frameWidth, _frameHeight, _x, _y));
				manager->remove(this);
				return;
			}
		}


	}
}

const bool Triangle::interactable(IFigure* object)
{

	Explosion* explosion = dynamic_cast<Explosion*>(object);
	return explosion == NULL;
}

void Triangle::makeReaction()
{
	IFigure* nearest = manager->nearest(this);

	if(nearest) followAway(nearest->getPosition());
}


