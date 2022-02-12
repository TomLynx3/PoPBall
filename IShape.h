#pragma once
#include <stdlib.h>
#include <math.h>

using namespace System::Drawing;


struct ShapeInitParams { int x; int y; int color; int size; int frameWidth; int frameHeight; float dx; float dy; };
enum Side {N,S,W,E};

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
	float getdX();
	float getdY();
	void setSpeed(float dX, float dY);
	void move();
	void followTo(int x, int y);

protected:
	float _x;
	float _y;
	int _color;
	int _size;
	int _frameWidth;
	int _frameHeight;
	float _dx;
	float _dy;

	bool checkColisionWithWall(Side side);
	float getCurrentSpeed();
	
};

