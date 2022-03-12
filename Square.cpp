#include "Square.h"

Square::Square(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 25;
}

const void Square::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));
	Pen pen(Color::FromArgb(158, 50, 168), 5);

	array<Point>^ points = gcnew array<Point>(4);

	Coordinates center = getCenterPosition();

	for (int i = 0; i < 4; i++) {
		points[i] = Point(
			center.x + _size * cos(_alpha + 2 * M_PI / 4 * i),
			center.y + _size * sin(_alpha + 2 * M_PI / 4 * i)
		);
	}

	graphics->DrawPolygon(% pen, points);
	graphics->FillPolygon(% brush, points);

}


void Square::interact(IFigure* object)
{
	Mover::interact(object);

	if (interactable(object)) {

		if (typeid(*object) == typeid(*this)) {


			if (rand() % 4 == 0 && manager->countOf(&typeid(*this)) < MAX_COUNT) {

				manager->place(new Square(_frameWidth, _frameHeight, 0, 0));
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

const bool Square::interactable(IFigure* object)
{

	Explosion* explosion = dynamic_cast<Explosion*>(object);
	return explosion == NULL;
}

void Square::makeReaction()
{
	IFigure* nearest = manager->nearest(this);

	if (nearest) {
		Coordinates pos = nearest->getPosition();
		if (typeid(*nearest) == typeid(*this)) {
			followTo(pos.x, pos.y);
		}
		else {
			followAway(pos);
		}
	}

}
