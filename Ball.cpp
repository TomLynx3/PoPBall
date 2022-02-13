#include "Ball.h"


Ball::Ball(ShapeInitParams params) : IShape(params)
{
	

	
}

void Ball::draw(Graphics^ graphics)
{

	Pen pen(Color::FromArgb(158,50,168),5);

	Rectangle displayRectangle =
		Rectangle(Point(_x-_size, _y - _size), Size(_size + _size, _size + _size));

	graphics->DrawEllipse(% pen, displayRectangle);

	SolidBrush brush(Color::FromArgb(_color));

	graphics->FillEllipse(%brush, displayRectangle);

	
}

void Ball::interact(IShape* object)
{

	Vector2 firstVelocityVector(_dx, _dy);
	Vector2 secondVelocityVector(object->getdX(), object->getdY());


	Coordinates objectCoord = object->getPosition();

	float alpha1 = atan2((objectCoord.y - _y), (objectCoord.x - _x));
	float beta1 = atan2(firstVelocityVector.getY(), firstVelocityVector.getX());
	float gamma1 = beta1 - alpha1;



	float decomp11 = firstVelocityVector.norm() * sin(gamma1);
	float decomp12 = firstVelocityVector.norm() * cos(gamma1);


	float alpha2 = atan2((_y - objectCoord.y), (_x - objectCoord.x));
	float beta2 = atan2(secondVelocityVector.getY(), secondVelocityVector.getX());
	float gamma2 = beta2 - alpha2;

	float decomp21 = secondVelocityVector.norm() * cos(gamma2);
	float decomp22 = secondVelocityVector.norm() * sin(gamma2);

	float subvector1 = ((_size  - object->getSize()) * decomp12  -2 * object->getSize() * decomp21) / (object->getSize()  + _size );
	float subvector2 = ((_size  - object->getSize())  * decomp21  +2 * _size * decomp12) / (object->getSize()  + _size );

	Vector2 v1(-sin(alpha1), cos(alpha1));
	Vector2 v2(-sin(alpha2), cos(alpha2));
	Vector2 v3(cos(alpha1), sin(alpha1));
	Vector2 v4(cos(alpha2), sin(alpha2));

	v1.multiple(decomp11);
	v3.multiple(subvector1);

	Vector2 newVec1 = v1.add(v3);

	v2.multiple(decomp22);
	v4.multiple(subvector2);

	Vector2 newVec2 = v2.substract(v4);


	_dx = newVec1.getX();
	_dy = newVec1.getY();

	object->setSpeed(newVec2.getX(), newVec2.getY());


}
