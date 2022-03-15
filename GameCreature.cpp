#include "GameCreature.h"


GameCreature::GameCreature(int frameWidth, int frameHeight, int x, int y,string name) : Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_size = 35;
	_state = CreatureState::WALK;
	_name = name;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(name.c_str()), CreatureState::WALK);
	_currentImageIndex = 0;

}

const void GameCreature::draw(Graphics^ graphics){

	List<Bitmap^>^ assets = Pictures::getHeroAssets(gcnew String(_name.c_str()), _state);

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));

	
	graphics->DrawImage(assets[_currentImageIndex], displayRectangle);
}

void GameCreature::interact(IFigure* object)
{
}

const bool GameCreature::interactable(IFigure* object)
{
	return false;
}

void GameCreature::makeReaction()
{
}

void GameCreature::animate()
{
	_currentImageIndex++;


	//if (_stateChangeRequested && _currentImageIndex == _lastImageIndex) {
	//	_stateChangeRequested = false;
	//	//_state = _stateToChange;
	//	_currentImageIndex = 0;
	//	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(_name.c_str()), _stateToChange);
	//	
	//}
	

	//if (_currentImageIndex == _lastImageIndex && _stateChangeRequested) {

	//	CreatureState state = _stateQueue.get();

	//	if (state != CreatureState::NOSTATE) {
	//		_state = state;
	//		_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(_name.c_str()), state);
	//		_stateChangeRequested = false;
	//	}
	//	//_currentImageIndex = 0;
	//}

	if (_currentImageIndex == _lastImageIndex) _currentImageIndex = 0;
}

void GameCreature::_setState(CreatureState state)
{
	if (_state == state) {
		return;
	}

	/*if (_currentImageIndex != _lastImageIndex) {
		

	}*/

	/*_stateChangeRequested = true;
	_stateQueue.add(state);*/

	_state = state;
	_currentImageIndex = 0;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(_name.c_str()), state);
}

