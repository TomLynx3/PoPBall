#include "Ball.h"

Ball* ball;

Ball::Ball(int frameWidth, int frameHeight)
{
	_frameWidth = frameWidth ;
	_frameHeight = frameHeight;

	_x = _frameWidth/2;
	_y = _frameHeight/2;
	_color = Color::FromArgb(50,145,168).ToArgb();
	_size = 30;
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
