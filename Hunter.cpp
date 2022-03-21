#include "Hunter.h"
#include "MainForm.h"
#include "Obstacle.h"

Hunter::Hunter(int frameWidth, int frameHeight, int x, int y, string name) :GameCreature(frameWidth, frameHeight, x, y, name)
{
	_dx = 3.0;
	_dy = 3.0;
	_state =CreatureState::IDLE;
	_dmg = 2;
	_hp = 10;
	_maxHP = 10;
	_armor = 2;
	_ammo = 20;
}

const void Hunter::draw(Graphics^ graphics)
{


	List<Bitmap^>^ assets = Pictures::getHeroAssets(gcnew String(_name.c_str()), _state);

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));

	/*
	//Image Rotation
	Point pt = System::Windows::Forms::Control::MousePosition;
	pt = OOPZerebkovs::MainForm::form->frame->PointToClient(pt);
	
	float angle = _getRotationAngle(pt);
	
	Bitmap^ img = Pictures::rotateImage(assets[_currentImageIndex], angle, graphics);

	delete img; */
	GameCreature::_drawHpBar(graphics);


	graphics->DrawImage(assets[_currentImageIndex],displayRectangle);

	
}

void Hunter::interact(IFigure* object)
{
	Bullet* bullet = dynamic_cast<Bullet*>(object);
	Minotaur* minotaur = dynamic_cast<Minotaur*>(object);

	if (bullet) {
		getDamaged(bullet->getDmg());
	}
	else if (minotaur) {
		if (minotaur->canMakeAttack() && _hp >0) {
			getDamaged(minotaur->getDmg());
		}
		
	}
	
	

}

void Hunter::addAmmo(int amount)
{
	int ammo = _ammo + amount;
	_ammo = ammo;

	if (ammo > 35) {
		_ammo = 35;
	}
	else {
		_ammo = ammo;
	}
}

void Hunter::addHp(int amount)
{
	int hp = _hp + amount;

	if (hp > _maxHP) {
		_hp = _maxHP;
	}
	else {
		_hp = hp;
	}
}

const bool Hunter::interactable(IFigure* object)
{
	Bullet* bullet = dynamic_cast<Bullet*>(object);
	GameCreature* monster = dynamic_cast<GameCreature*>(object);
	Obstacle* obstacle = dynamic_cast<Obstacle*>(object);

	return monster != NULL || bullet != NULL || obstacle != NULL;
}
void Hunter::makeReaction()
{
}



float Hunter::_getRotationAngle(Point pt)
{

	Vector2 vec = Vector2(pt.X, pt.Y);
	Vector2 vec1 = Vector2(_x,_y);
	
	Vector2 vec3 = vec.substract(vec1);

	return atan2(vec3.getY(), vec3.getX()) * (180 / M_PI);
}

const Vector2 Hunter::_getVectorToCursor(int speedAcceleration)
{
	Point pt = System::Windows::Forms::Control::MousePosition;
	pt = OOPZerebkovs::MainForm::form->frame->PointToClient(pt);

	float deltaX = pt.X - _x;
	float deltaY = pt.Y - _y;

	float angle = atan2(deltaY, deltaX);

	float dx = speedAcceleration * cos(angle);

	float dy = speedAcceleration * sin(angle);

	return Vector2(dx,dy);
}

void Hunter::_onDie()
{
	manager->endGame();
}


void Hunter::move()
{
	if (_state == CreatureState::WALK) {

	

		int x = _x + _dx;
		int y = _y +_dy;

		
		if ((x - _size) <= 0 || (x + _size) >= _frameWidth) {
			x = _x;
		}

		if ((y - _size) <= 0 || (y + _size) >= _frameHeight) {
			y = _y;
		}


		IFigure* fig = manager->findObjectIfCollision(this, &typeid(Obstacle));
		
		Obstacle* obstacle = dynamic_cast<Obstacle*>(fig);
		
		if (obstacle) {
			Coordinates pos = obstacle->getPosition();
			int size = obstacle->getSize();

			int startX = pos.x - size;
			int startY = pos.y-size;

			int endX = startX + (2*size);
			int endY = startY + (2* size);

			if (x >= startX && x <= endX && y >= startY && y <= endY) {
				x = _x;
				y = _y;
			}

		}
		_x = x;
		_y = y;
		
	}

	
}

void Hunter::doCommand(Command cmd)
{
	
	switch (cmd)
	{
	case Command::STARTUP:
		{
			_setState(CreatureState::WALK);

			Vector2 vec = _getVectorToCursor(3);
			_dx = vec.getX();
			_dy = vec.getY();
		}
		break;
	case Command::STARTLEFT:
		_setState(CreatureState::WALK);
		_dy = 0;
		_dx = -3;
		break;
	case Command::STARTRIGHT:
		_setState(CreatureState::WALK);
		_dy = 0;
		_dx = 3;
		break;
	case Command::STARTDOWN:	
		{
		_setState(CreatureState::WALK);

		Vector2 vec = _getVectorToCursor(3);
		_dx = -vec.getX();
		_dy = -vec.getY();
			
		}
		break;
	case Command::STOPLEFT:
	case Command::STOPUP:
	case Command::STOPRIGHT:
	case Command::STOPDOWN:
		_setState(CreatureState::IDLE);
		_dy = 0;
		_dx = 0;
		break;
	case Command::ATTACK:	
	{
		if (_ammo == 0) {
			return;
		}
		_setState(CreatureState::ATTACK);

		Point pt = System::Windows::Forms::Control::MousePosition;
		pt = OOPZerebkovs::MainForm::form->frame->PointToClient(pt);


		Coordinates center = getCenterPosition();

		float D = sqrt((pt.X-_x) * (pt.X-_x) + (pt.Y-_y) * (pt.Y-_y));

		float xb = _x + (_size *2) / D * (pt.X - _x);
		float yb =_y + (_size * 2) / D * (pt.Y - _y);

		float dxb = 10 / D * (pt.X - _x);
		float dyb = 10 / D * (pt.Y - _y);


		Bullet* bullet = new Bullet(_frameWidth, _frameHeight,xb,yb,_dmg);


		bullet->setSpeed(dxb,dyb);

		manager->add(bullet);
		_ammo--;
		break;
	}
	case Command::STOPATTACK:
	{
		
		_setState(CreatureState::IDLE);
		break;
	}
	case Command::DYING:
	{	
		_setState(CreatureState::DYING);
		
		break;
	}
	case Command::HURT:
	{
		_setState(CreatureState::HURT);
		break;
	}
	case Command::STOPHURT:
		_setState(CreatureState::IDLE);
		break;
	case Command::STOPDYING:
	{
		_onDie();
		break;
	}
	default:
		break;
	}

}





