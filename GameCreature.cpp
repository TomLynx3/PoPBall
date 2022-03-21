#include "GameCreature.h"
#include "Bullet.h"
#include "Hunter.h"
#include "Minotaur.h"
#include "Obstacle.h"



GameCreature::GameCreature(int frameWidth, int frameHeight, int x, int y,string name) : Mover(frameWidth,frameHeight)
{
	_x = x;
	_y = y;
	_size = 35;
	_state = CreatureState::WALK;
	_name = name;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(name.c_str()),_state);
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

	
	_drawHpBar(graphics);
	graphics->DrawImage(assets[_currentImageIndex], displayRectangle);

	
}



const bool GameCreature::interactable(IFigure* object)
{
	Bullet* bullet = dynamic_cast<Bullet*>(object);
	Hunter* hunter = dynamic_cast<Hunter*>(object);

	return hunter != NULL || bullet != NULL;
}

void GameCreature::interact(IFigure* object)
{

	Hunter* hunter = dynamic_cast<Hunter*>(object);
	Minotaur* minotaur = dynamic_cast<Minotaur*>(object);
	Obstacle* obstacle= dynamic_cast<Obstacle*>(object);

	if (hunter) {
		doCommand(Command::ATTACK);
	}
	else if(minotaur) {
		Coordinates pos = minotaur->getPosition();
		followAway(Coordinates{ pos.x,pos.y });
	}
	else if (obstacle) {
		_dx = -_dx;
		_dy = -_dy;
	}
}


void GameCreature::animate()
{
	_currentImageIndex++;

	if((_isHurt || _isDying ) && _currentImageIndex == _lastImageIndex){
		Command cmd = cmd;


		cmd = _isHurt ? Command::STOPHURT : Command::STOPDYING;

		_isHurt = false;
		
		
		doCommand(cmd);

		_currentImageIndex = 0;
		return;
	}

	if (_currentImageIndex == _lastImageIndex) _currentImageIndex = 0;
}

void GameCreature::getDamaged(int dmg)
{
	doCommand(Command::HURT);
	_isHurt = true;
	float resistance = (_armor / 15) * dmg;

	float hp = dmg - resistance;

	_hp -= hp;
	
	if (_hp <= 0) {
 		_isHurt = false;
		_isDying = true;
		doCommand(Command::DYING);
		
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

const int GameCreature::getDmg()
{
	return _dmg;
}

const Coordinates GameCreature::getCenterPosition()
{
	return Coordinates{ _x, _y };
}


void GameCreature::_setState(CreatureState state)
{
	if (_state == state) {
		return;
	}

	_state = state;
	_currentImageIndex = 0;
	_lastImageIndex = Pictures::getHeroAssetLastImageIndex(gcnew String(_name.c_str()),state);
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

