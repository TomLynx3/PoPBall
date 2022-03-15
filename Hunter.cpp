#include "Hunter.h"
#include "MainForm.h"





Hunter::Hunter(int frameWidth, int frameHeight, int x, int y, string name) :GameCreature(frameWidth, frameHeight, x, y, name)
{
	_dx = 10.0;
	_dy = 10.0;
	_state =CreatureState::IDLE;
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

	graphics->DrawImage(img, displayRectangle);

	//Memory leak! I thought managed objects are disposed by garbage collector!
	delete img;
	
	
}

float Hunter::_getRotationAngle(Point pt)
{
	Coordinates center = getCenterPosition();

	Vector2 vec = Vector2(pt.X, pt.Y);
	Vector2 vec1 = Vector2(center.x,center.y);

	Vector2 vec3 = vec.substract(vec1);

	return atan2(vec3.getY(), vec3.getX()) * (180 / M_PI);
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
	Point pt = System::Windows::Forms::Control::MousePosition;
	pt = OOPZerebkovs::MainForm::form->frame->PointToClient(pt);
	switch (cmd)
	{
	case Command::STARTUP:
		_setState(CreatureState::WALK);

		
		{
			float deltaX = pt.X - _x;
			float deltaY = pt.Y - _y;

			float angle = atan2(deltaY, deltaX);

			float dx = 3 * cos(angle);

			float dy = 3 * sin(angle);

			_dx = dx;
			_dy = dy;
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
			{
				float deltaX = pt.X - _x;
				float deltaY = pt.Y - _y;

				float angle = atan2(deltaY, deltaX);

				float dx = 3 * cos(angle);

				float dy = 3 * sin(angle);

				_dx = -dx;
				_dy = -dy;
			}
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
		_setState(CreatureState::ATTACK);
	{
		float deltaX = pt.X - _x;
		float deltaY = pt.Y - _y;

		float angle = atan2(deltaY, deltaX);

		float dx = 5 * cos(angle);

		float dy = 5 * sin(angle);

		Bullet* ball = new Bullet(_frameWidth, _frameHeight,_x + 10,_y);
	
		ball->setSpeed(dx, dy);
		manager->add(ball);
		break;
	}
	case Command::STOPSHOOT:
	{
		
		_setState(CreatureState::IDLE);
	}
		
	break;

	default:
		break;
	}

}





