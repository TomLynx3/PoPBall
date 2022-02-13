#include "Manager.h"

Manager* manager;


Manager::Manager(int frameWidth, int frameHeight)
{
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;

	for (int i = 0; i < MAX_OBJECTS; i++) {
		_objects[i] = NULL;
	}
}

Manager::~Manager()
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (_objects[i]) {
			delete _objects[i];
		}
	}
}

void Manager::add(IShape* object)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!_objects[i]) {
			_objects[i] = object;
			break;
		}
	}
}

ShapeInitParams Manager::createRandomObjectParams(int x, int y)
{
	ShapeInitParams params;

	params.x = x;
	params.y = y;
	params.color = Color::FromArgb(rand() % 256, rand() % 256, rand() % 256).ToArgb();
	params.size = 15;
	params.frameWidth = _frameWidth;
	params.frameHeight = _frameHeight;
	params.dx = rand() % 20 + (-10);
	params.dy = rand() % 20 + (-10);

	return params;
}

void Manager::drawFrame(Graphics^ graphics)
{
	graphics->FillRectangle(% SolidBrush(Color::FromArgb(217, 212, 212)), 0, 0, _frameWidth, _frameHeight);

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (_objects[i]) {
			_objects[i]->draw(graphics);
		}
	}
}

void Manager::move()
{


	for (int i = 0; i < MAX_OBJECTS; i++) {

		if (!_objects[i]) {
			continue;
		}

		for (int j = 0; j < MAX_OBJECTS; j++) {
			if (!_objects[j] || _objects[i] == _objects[j]) {
				continue;
			}

			bool isCollision = checkCollision(_objects[i], _objects[j]);

			if (isCollision) {
				
				_objects[i]->interact(_objects[j]);
				_objects[i]->move();
				_objects[j]->move();
				
				
			}
		}

		_objects[i]->move();
	}
}

bool Manager::checkCollision(IShape* first, IShape* second)
{
	Coordinates firstCoord = first->getCenterPosition();
	Coordinates secondCoord = second->getCenterPosition();

	float dist = sqrt(pow((secondCoord.x-firstCoord.x),2) + pow((secondCoord.y - firstCoord.y),2));

	return dist < (first->getSize() + second->getSize());
}

IShape* Manager::search(Coordinates coord)
{

	for (int i = 0; i < MAX_OBJECTS; i++) {
		IShape* object = _objects[i];

		if (!object) {
			continue;
		}

		Coordinates objectCenter = object->getCenterPosition();

		float dist = sqrt(pow((coord.x-objectCenter.x),2)+pow((coord.y-objectCenter.y),2));
		
		if (dist < object->getSize() + object->getSize()) {
			return object;
		}
	}
	return nullptr;
}

void Manager::remove(IShape* object)
{
	for (int i= 0; i < MAX_OBJECTS; i++) {
		
		if (_objects[i] == object) {
			delete object;
			_objects[i] = nullptr;
			break;
		}
	}
}

void Manager::increaseSpeed()
{
	for (int i = 0; i < MAX_OBJECTS; i++) {

		if (!_objects[i]) {
			continue;
		}

		float dx = _objects[i]->getdX();
		float dy = _objects[i]->getdY();

		if (fabs(dx) < 50) {
			dx *= 1.3;
		}

		if (fabs(dy) < 50) {
			dy *= 1.3;
		}

		_objects[i]->setSpeed(dx, dy);
	}
}

void Manager::decreaseSpeed()
{
	for (int i = 0; i < MAX_OBJECTS; i++) {

		if (!_objects[i]) {
			continue;
		}

		float dx = _objects[i]->getdX();
		float dy = _objects[i]->getdY();

		if (fabs(dx) >= 1) {
			dx *= 0.3;
		}

		if (fabs(dy) >=1) {
			dy *= 0.3;
		}

		_objects[i]->setSpeed(dx, dy);
	}
}
