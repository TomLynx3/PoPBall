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

void Manager::add(IFigure* object)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (!_objects[i]) {
			_objects[i] = object;
			break;
		}
	}
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
			if (!_objects[j] || _objects[i] == _objects[j] || !_objects[i]) {
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

bool Manager::checkCollision(IFigure* first, IFigure* second)
{
	Coordinates firstCoord = first->getCenterPosition();
	Coordinates secondCoord = second->getCenterPosition();

	float dist = sqrt(pow((secondCoord.x-firstCoord.x),2) + pow((secondCoord.y - firstCoord.y),2));

	return dist < (first->getSize() + second->getSize());
}

IFigure* Manager::search(Coordinates coord)
{

	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* object = _objects[i];

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

void Manager::remove(IFigure* object)
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

IFigure* Manager::createRandomFigure(int frameWidth, int frameHeight, int x, int y)
{
	int random = rand() % FIGURE_TYPE_COUNT;

	IFigure* object;

	switch ((FigureType)random) {
		case FigureType::STAR:
			object = new Star(frameWidth, frameHeight, x, y);
			break;
		case FigureType::BALL:
			object = new Ball(frameWidth, frameHeight);
			break;
		case FigureType::RECTANGLE:
			object = new Square(frameWidth, frameHeight, x, y);
			break;
		case FigureType::TRIANGLE:
			object = new Triangle(frameWidth, frameHeight, x, y);
			break;
		default:
			object = new Ball(frameWidth, frameHeight);
	}


	return object;
}

