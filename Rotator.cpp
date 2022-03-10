#include "Rotator.h"

Rotator::Rotator(int frameWidth, int frameHeight, int x, int y):Mover(frameWidth,frameHeight)
{
	_alpha =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2* M_PI )));;
	_dAlpha = (2 * M_PI)/100 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (((2 * M_PI) / 30) - ((2 * M_PI) / 100))));
	
}

void Rotator::move()
{
	Mover::move();
	_alpha += _dAlpha;
}
