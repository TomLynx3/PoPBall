#pragma once
#include <math.h>

class Vector2
{
public:
	Vector2(float x, float y);
	float getX();
	float getY();
	float norm();
	void multiple(float number);
	Vector2 add(Vector2 vector);
	Vector2 substract(Vector2 vector);
private:
	float _x;
	float _y;
};

