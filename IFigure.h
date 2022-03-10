
#include <stdlib.h>
#include <math.h>

using namespace System::Drawing;
struct Coordinates { float x; float y; };
enum Side { N, S, W, E };

#pragma once
class IFigure
{
public:
	virtual const void draw(Graphics^ graphics) = 0;
	virtual void interact(IFigure* object) = 0;
	virtual void setPos(int x, int y) = 0;
	virtual const int getColor() =0;
	virtual void setColor(int color) =0;
	virtual const int getSize() = 0;
	virtual void setSize(int size) =0;
	virtual void setRandomColor() =0;
	virtual const float getdX() = 0;
	virtual const float getdY() =0;
	virtual void setSpeed(float dX, float dY) =0;
	virtual void move() =0;
	virtual void followTo(int x, int y) =0;
	virtual const Coordinates getCenterPosition() =0;
	virtual const Coordinates getPosition() =0;
	virtual void interactReaction() = 0;

protected:
	virtual const bool checkColisionWithWall(Side side) = 0 ;
	virtual const float getCurrentSpeed() = 0;
};

