#include "Ball.h"


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

void Ball::interactReaction()
{
	if (getCurrentSpeed() == 0) {
		
		_dx= rand() % 20 + (-10);
		_dy = rand() % 20 + (-10);
	}
}
