#pragma once
#include <stdlib.h>

using namespace System::Drawing;
class IShape
{
public:

	virtual void Draw(Graphics^ graphics) = 0;
	
	void SetPos(int x, int y);
	int GetColor();
	void SetColor(int color);
	int GetSize();
	void SetSize(int size);
	void SetRandomColor();

protected:
	float _x;
	float _y;
	int _color;
	int _size;
	int _frameWidth;
	int _frameHeight;
};

