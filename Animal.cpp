#include "Animal.h"

Animal::Animal(int frameWidth, int frameHeight, int x, int y) :Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_size = 25;
	_currentImageIndex = 0;
}

const void Animal::draw(Graphics^ graphics)
{
	List<Bitmap^>^ assets = Pictures::getHeroAssets("Minotaur",CreatureState::WALK);

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));
	
	graphics->DrawImage(assets[_currentImageIndex], displayRectangle);
}

void Animal::interact(IFigure* object)
{
}

const bool Animal::interactable(IFigure* object)
{
	return false;
}

void Animal::makeReaction()
{
}

void Animal::animate()
{
	_currentImageIndex++;
	if (_currentImageIndex == 17) _currentImageIndex = 0;
}


