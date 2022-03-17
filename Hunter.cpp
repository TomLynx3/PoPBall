#include "Hunter.h"
#include "MainForm.h"

Hunter::Hunter(int frameWidth, int frameHeight, int x, int y, string name) :GameCreature(frameWidth, frameHeight, x, y, name)
{
	_dx = 10.0;
	_dy = 10.0;
	_state =CreatureState::IDLE;
	_dmg = 3;
	_hp = 10;
	_maxHP = 10;
	_armor = 2;
	_ammo = 5;
}

const void Hunter::draw(Graphics^ graphics)
{
	Point pt = System::Windows::Forms::Control::MousePosition;
	pt = OOPZerebkovs::MainForm::form->frame->PointToClient(pt);

	List<Bitmap^>^ assets = Pictures::getHeroAssets(gcnew String(_name.c_str()), _state);

	Rectangle displayRectangle =
		Rectangle(Point(_x - _size, _y - _size), Size(_size + _size, _size + _size));
	

	float angle = _getRotationAngle(pt);
	
	Bitmap^ img = Pictures::rotateImage(assets[_currentImageIndex], angle, graphics);


	GameCreature::_drawHpBar(graphics);

	graphics->DrawImage(img, displayRectangle);

	delete img;
	
	
}

void Hunter::interact(IFigure* object)
{
	Bullet* bullet = dynamic_cast<Bullet*>(object);

	if (bullet) {
		
	}
}

void Hunter::addAmmo(int amount)
{
	int ammo = _ammo + amount;
	
	if (ammo > 15) {
		_ammo = 15;
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

	}
}


float Hunter::_getRotationAngle(Point pt)
{
	Coordinates center = getCenterPosition();

	Vector2 vec = Vector2(pt.X, pt.Y);
	Vector2 vec1 = Vector2(center.x,center.y);

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


void Hunter::move()
{
	if (_state == CreatureState::WALK) {

		_x += _dx;
		_y += _dy;

		if (checkColisionWithWall(Side::W) || checkColisionWithWall(Side::E)) {
			_dx = -_dx;
		}

		if (checkColisionWithWall(Side::N) || checkColisionWithWall(Side::S)) {
			_dy = -_dy;
		}
	}

	
}

void Hunter::doCommand(Command cmd)
{
	
	switch (cmd)
	{
	case Command::STARTUP:
		_setState(CreatureState::WALK);
		{
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
		_setState(CreatureState::WALK);
		{

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
	case Command::SHOOT:	
	{
		if (_ammo == 0) {
			return;
		}
		_setState(CreatureState::ATTACK);

		Vector2 vec = _getVectorToCursor(5);

		Bullet* ball = new Bullet(_frameWidth, _frameHeight,_x + 10,_y,_dmg);
	
		ball->setSpeed(vec.getX(), vec.getY());

		manager->add(ball);
		_ammo--;
		break;
	}
	case Command::STOPSHOOT:
	{
		
		_setState(CreatureState::IDLE);
		break;
	}
	case Command::DIE:
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
	default:
		break;
	}

}





