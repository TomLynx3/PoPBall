#pragma once
#include <stdlib.h>
#include <math.h>

using namespace System::Drawing;

struct ShapeInitParams { int x; int y; int color; int size; int frameWidth; int frameHeight; float dx; float dy; };
enum Side {N,S,W,E};
struct Coordinates { float x; float y; };

class IShape
{
public:


	IShape(ShapeInitParams params);

	virtual void draw(Graphics^ graphics) = 0;
	virtual void interact(IShape* object) = 0;
	
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
	Coordinates getCenterPosition();
	Coordinates getPosition();


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

