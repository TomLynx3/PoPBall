#include "IShape.h"

void IShape::SetPos(int x, int y)
{


	if ((_size < x && x < (_frameWidth - _size)) && (_size < y && y < (_frameHeight - _size))) {
		_x = x;
		_y = y;
	}
}

int IShape::GetColor()
{
	return _color;
}

void IShape::SetColor(int color)
{
	_color = color;
}

int IShape::GetSize()
{
	return _size;
}

void IShape::SetSize(int size)
{
	_size = size;
}

void IShape::SetRandomColor()
{
	SetColor(Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb());
}
