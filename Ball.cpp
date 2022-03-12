#include "Ball.h"
#include "Explosion.h"


Ball::Ball(int frameWidth, int frameHeight) : Mover(frameWidth,frameHeight)
{
	

	
}

const void Ball::draw(Graphics^ graphics)
{

	Pen pen(Color::FromArgb(158,50,168),5);

	Rectangle displayRectangle =
		Rectangle(Point(_x-_size, _y - _size), Size(_size + _size, _size + _size));

	graphics->DrawEllipse(% pen, displayRectangle);

	SolidBrush brush(Color::FromArgb(_color));

	graphics->FillEllipse(%brush, displayRectangle);

	
}


void Ball::interact(IFigure* object)
{
	Mover::interact(object);

	if (interactable(object)) {

		if (typeid(*object) == typeid(*this)) {


			if (rand() % 4 == 0 && manager->countOf(&typeid(*this)) < MAX_COUNT) {

				manager->place(new Ball(_frameWidth, _frameHeight));
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

const bool Ball::interactable(IFigure* object)
{
	Explosion* explosion = dynamic_cast<Explosion*>(object);
	return explosion == NULL;
}

void Ball::makeReaction()
{

		IFigure* nearestFriend = manager->nearestFriend(this);

		if (nearestFriend) {

			Coordinates pos = nearestFriend->getPosition();
			followTo(pos.x, pos.y);
		}
}

