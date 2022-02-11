#include "IShape.h"

IShape::IShape(ShapeInitParams params)
{
	_x = params.x;
	_y = params.y;
	_size = params.size;
	_color = params.color;
	_frameWidth = params.frameWidth;
	_frameHeight = params.frameHeight;
}

void IShape::setPos(int x, int y)
{

	if (_size < x && x < (_frameWidth - _size)) {
		_x=x;
	}

	if (_size < y && y < (_frameHeight - _size)) {
		_y =y;
	}
}

int IShape::getColor()
{
	return _color;
}

void IShape::setColor(int color)
{
	_color = color;
}

int IShape::getSize()
{
	return _size;
}

void IShape::setSize(int size)
{
	if (size <= 1 || size >=100) {
		return;
	}


	if ((_x - _size -5 <= 0)) {
		_x += 5;	
	}
	 
	if ((_x + _size + 5) >= _frameWidth) {
		_x -= 5;
	}

	if ((_y - _size - 5 <= 0)) {
		_y += 5;
	}

	if ((_y + _size + 5) >= _frameHeight) {
		_y -= 5;
	}

	_size = size;
}

void IShape::setRandomColor()
{
	setColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
}
