#include "Minotaur.h"
#include "Manager.h"
#include "AmmoPack.h"
#include "LifePoints.h"

Minotaur::Minotaur(int frameWidth, int frameHeight, int x, int y, string name) : GameCreature(frameWidth, frameHeight, x, y, name)
{
	_name = name;
	_dx = 2;
	_dy = 2;
	_state = CreatureState::WALK;
	_dmg = 5;
	_hp = 5;
	_maxHP = 5;
	_armor = 2;
}

void Minotaur::move()
{
	
	if (_isDying) {
		return;
	}
	_x += _dx;
	_y += _dy;
	
	if (_cooldown == 0) {
		_isAttackReady = true;
	}
	else {
		if (_cooldown > 0) {
			_cooldown--;
		}
		
	}
}

void Minotaur::doCommand(Command cmd)
{
	switch (cmd)
	{
	case Command::ATTACK:
	{
		if (_isAttackReady) {
			_setState(CreatureState::ATTACK);
			_isAttackReady = false;
			_cooldown = 30;
			_dx = 0;
			_dy = 0;

		}

		break;
	}
		
	case Command::STARTUP:
		break;
	case Command::STOPUP:
		break;
	case Command::STARTRIGHT:
		break;
	case Command::STARTLEFT:
		break;
	case Command::STOPLEFT:
		break;
	case Command::STOPRIGHT:
		break;
	case Command::STARTDOWN:
		break;
	case Command::STOPDOWN:
		break;
	case Command::STOPATTACK:
		break;
	case Command::DYING:
		_setState(CreatureState::DYING);
		break;
	case Command::STOPDYING:
		_onDie();
		break;
	case Command::HURT:
		_dx = 0;
		_dy = 0;
		_setState(CreatureState::HURT);
		break;
	case Command::STOPHURT:
		_setState(CreatureState::WALK);
		break;
	default:
		break;
	}
}

void Minotaur::makeReaction()
{
	IFigure* nearestEnemy = manager->nearestAlien(this);

	if (nearestEnemy) {
		Coordinates pos = nearestEnemy->getPosition();
		_dx = 2;
		_dy = 2;
		_setState(CreatureState::WALK);
		followTo(pos.x, pos.y);
	}
}

bool Minotaur::canMakeAttack()
{
	return _isAttackReady && _hp >0;
}

void Minotaur::_onDie()
{

	manager->addScore(1);

	int number = rand() % 2;

	if (number == 0) {
		int random = rand() % 2;

		if (random == 0) {
			manager->place(new AmmoPack(_frameWidth, _frameHeight, _x, _y));
		}
		else {
			manager->place(new LifePoints(_frameWidth, _frameHeight, _x, _y));
		}
	}

	manager->remove(this);
}


