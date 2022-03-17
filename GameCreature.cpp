#include "GameCreature.h"
#include "Bullet.h"



GameCreature::GameCreature(int frameWidth, int frameHeight, int x, int y,string name) : Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_size = 35;
	_state = CreatureState::WALK;
	_name = name;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(name.c_str()));
	_currentImageIndex = 0;
	_armor = 5;
	_hp = 5;
	_maxHP = 5;
	_ammo = 0;

}

const void GameCreature::draw(Graphics^ graphics){

	List<Bitmap^>^ assets = Pictures::getHeroAssets(gcnew String(_name.c_str()), _state);

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));

	
	graphics->DrawImage(assets[_currentImageIndex], displayRectangle);

}



const bool GameCreature::interactable(IFigure* object)
{
	Bullet* bullet = dynamic_cast<Bullet*>(object);
	return bullet != NULL;
}

void GameCreature::makeReaction()
{
}

void GameCreature::animate()
{
	_currentImageIndex++;

	if(isHurt && _currentImageIndex == _lastImageIndex){
		isHurt = false;
		doCommand(Command::STOPHURT);
		_currentImageIndex = 0;
		return;
	}

	if (_currentImageIndex == _lastImageIndex) _currentImageIndex = 0;
}

void GameCreature::getDamaged(int dmg)
{
	doCommand(Command::HURT);
	float resistance = (_armor / 15) * dmg;

	float hp = dmg - resistance;

	_hp -= hp;
	isHurt = true;
	if (_hp <= 0) {
		doCommand(Command::DIE);
	}
}

const int GameCreature::getArmor()
{
	return _armor;
}

const float GameCreature::getHpInPercentages()
{
	return	(_hp / _maxHP) * 100;
}

const int GameCreature::getAmmoAmount()
{
	return _ammo;
}

const int GameCreature::getAmmoLabelColor()
{

	if (_ammo >= 0 && _ammo <= 5) {
		return Color::FromArgb(255, 0, 0).ToArgb();
	}
	else if (_ammo > 5 && _ammo < 10) {
		return  Color::FromArgb(227, 227, 69).ToArgb();
	}
	else {
		return Color::FromArgb(0, 255, 0).ToArgb();
	}
}

const int GameCreature::getHpLabelColor()
{
	float value = getHpInPercentages();

	if (value >= 0 && value <= 30) {
		return Color::FromArgb(255, 0, 0).ToArgb();
	}
	else if (value > 30 && value < 70) {
		return  Color::FromArgb(227, 227, 69).ToArgb();
	}
	else {
		return Color::FromArgb(0, 255, 0).ToArgb();
	}
}



void GameCreature::_setState(CreatureState state)
{
	if (_state == state) {
		return;
	}

	_state = state;
	_currentImageIndex = 0;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(_name.c_str()));
}

void GameCreature::_drawHpBar(Graphics^ g)
{
	int totalLength = 75;

	int greenLength = (_hp * totalLength) / _maxHP;

	Rectangle redRectangle =
		Rectangle(Point(_x - 40, _y - 50), Size(totalLength, 12));
	SolidBrush redBrush(Color::Red);

	g->FillRectangle(% redBrush, redRectangle);

	Rectangle greenRectangle =
		Rectangle(Point(_x-40, _y - 50), Size(greenLength,12));
	SolidBrush brush(Color::Green);

	g->FillRectangle(% brush, greenRectangle);

	

}

