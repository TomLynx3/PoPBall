#pragma once
#include <stdlib.h>

using namespace System::Drawing;


struct ShapeInitParams { int x; int y; int color; int size; int frameWidth; int frameHeight; };

class IShape
{
public:


	IShape(ShapeInitParams params);

	virtual void Draw(Graphics^ graphics) = 0;
	
	void setPos(int x, int y);
	int getColor();
	void setColor(int color);
	int getSize();
	void setSize(int size);
	void setRandomColor();

protected:
	float _x;
	float _y;
	int _color;
	int _size;
	int _frameWidth;
	int _frameHeight;
};

