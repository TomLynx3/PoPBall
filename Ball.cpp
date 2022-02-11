#include "Ball.h"

Ball* ball;

Ball::Ball(ShapeInitParams params) : IShape(params)
{
	

	
}

void Ball::Draw(Graphics^ graphics)
{

	Pen pen(Color::FromArgb(158,50,168),5);

	Rectangle displayRectangle =
		Rectangle(Point(_x-_size, _y - _size), Size(_size + _size, _size + _size));

	graphics->DrawEllipse(% pen, displayRectangle);

	SolidBrush brush(Color::FromArgb(_color));

	graphics->FillEllipse(%brush, displayRectangle);

	
}
