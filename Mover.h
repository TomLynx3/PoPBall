#include "Vector2.h"
#pragma once
#include "IFigure.h"
class Mover :
    public IFigure
{
public:

	Mover(int frameWidth, int frameHeight);

	void setPos(int x, int y);
	const int getColor();
	void setColor(int color);
	const int getSize();
	void setSize(int size);
	void setRandomColor();
	const float getdX();
	const float getdY();
	virtual void setSpeed(float dX, float dY);
	void move();
	void followTo(int x, int y);
	const Coordinates getCenterPosition();
	const Coordinates getPosition();
	const float getCurrentSpeed();
	void interact(IFigure* object) override;
	bool interactable(IFigure* object) override;

protected:
	float _x;
	float _y;
	int _color;
	int _size;
	int _frameWidth;
	int _frameHeight;
	float _dx;
	float _dy;

private:
	const bool checkColisionWithWall(Side side);

};
