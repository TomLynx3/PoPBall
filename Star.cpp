#include "Star.h"

Star::Star(int frameWidth, int frameHeight, int x, int y) : Rotator(frameWidth,frameHeight,x,y)
{
	_size = 20;
}

const void Star::draw(Graphics^ graphics)
{
	SolidBrush brush(Color::FromArgb(_color));
	Pen pen(Color::FromArgb(158, 50, 168), 5);

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


	graphics->DrawPolygon(% pen, points);
	graphics->FillPolygon(% brush, points);
}


void Star::interact(IFigure* object)
{
	Mover::interact(object);

	if (interactable(object)) {
		
		if (typeid(*object) == typeid(*this)) {
			

			if (rand() % 4 == 0 && manager->countOf(&typeid(*this)) < MAX_COUNT) {
				
				manager->place(new Star(_frameWidth, _frameHeight, 0, 0));
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

const bool Star::interactable(IFigure* object)
{
	Explosion* explosion = dynamic_cast<Explosion*>(object);
	return explosion == NULL;
}

void Star::makeReaction()
{
	IFigure* nearestEnemy = manager->nearestAlien(this);

	if (nearestEnemy) {
		Coordinates pos = nearestEnemy->getPosition();
		followTo(pos.x,pos.y);
	}

}
