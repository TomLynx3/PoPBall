#include "Manager.h"
#include "Pictures.h"
#include "MainForm.h"

using namespace System::Windows::Forms;

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
	//graphics->DrawImage(Pictures::bgImage, 0, 0,_frameWidth,_frameHeight);

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
				
				if (_objects[i]->interactable(_objects[j])) {
					_objects[i]->interact(_objects[j]);
				}
				

				if (_objects[i]) _objects[i]->move();
				if (_objects[j]) _objects[j]->move();
				
				
			}
		}
		
		if(_objects[i]) _objects[i]->move();
	}
}

void Manager::makeReactions()
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (_objects[i]) {
			_objects[i]->makeReaction();
		}
	}
}

bool Manager::checkCollision(IFigure* first, IFigure* second)
{
	Coordinates firstCoord = first->getCenterPosition();
	Coordinates secondCoord = second->getCenterPosition();

	float dist = sqrt(pow((secondCoord.x-firstCoord.x),2) + pow((secondCoord.y - firstCoord.y),2));

	return dist < (first->getSize() + second->getSize());
}

Coordinates Manager::getRandomCoordinates(IFigure* object)
{

	return Coordinates{ (float)(rand() % _frameWidth - object->getSize()) , (float)(rand() % _frameHeight - object->getSize()) };
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

IFigure* Manager::search(const type_info* type)
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* obj = _objects[i];

		if (obj && typeid(*obj) == *type) {
			return obj;
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

int Manager::countOf(const type_info* type)
{
	int count = 0;

	for (IFigure* object : _objects) {
		if (object &&  typeid(*object) == *type) count++;
	}

	return count;
}

const void Manager::place(IFigure* object)
{
	Coordinates coord = getRandomCoordinates(object);

	object->setPos(coord.x, coord.y);

	int attemps = 0;

	while (attemps < 200) {
		bool found = false;
		for (int i = 0;i < MAX_OBJECTS; i++) {
			if (_objects[i] && checkCollision(_objects[i], object)) {
				coord = getRandomCoordinates(object);
				found = true;
				object->setPos(coord.x, coord.y);
				attemps++;
				break;
			}
		}

		if (!found) {
			return add(object);
		}
	}

	delete object;
	
}

void Manager::explodeAllObjects()
{
	
	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* object = _objects[i];
		if (object && dynamic_cast<Explosion*>(object) == NULL) {
			Coordinates position = object->getPosition();
			delete object;
			_objects[i] = new Explosion(_frameWidth, _frameHeight, position.x, position.y);
		}
	}

}

IFigure* Manager::nearestFriend(IFigure* object)
{
	IFigure* nearest = nullptr;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* fig = _objects[i];

		if (fig && typeid(*object) == typeid(*fig) && fig != object) {

			if (nearest) {
				
				double distance = nearest->getDistance(object);
				double distance2 = fig->getDistance(object);

				if (distance2 > distance) nearest = fig;
			}
			else {
				nearest = fig;
			}
		}
	}

	return nearest;
}

IFigure* Manager::nearestAlien(IFigure* object)
{
	IFigure* nearest = nullptr;

	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* fig = _objects[i];

		if (fig && typeid(*object) != typeid(*fig) && fig != object) {

			if (nearest) {

				double distance = nearest->getDistance(object);
				double distance2 = fig->getDistance(object);

				if (distance2 > distance) nearest = fig;
			}
			else {
				nearest = fig;
			}
		}
	}
	return nearest;
}

IFigure* Manager::nearest(IFigure* object)
{
	IFigure* nearest = nullptr;

	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* fig = _objects[i];

		if (fig) {

			if (nearest) {

				double distance = nearest->getDistance(object);
				double distance2 = fig->getDistance(object);

				if (distance2 > distance) nearest = fig;
			}
			else {
				nearest = fig;
			}
		}
	}
	return nearest;
}

IFigure* Manager::findObjectIfCollision(IFigure* obj, const type_info* type)
{

	for (int i = 0; i < MAX_OBJECTS; i++) {
		IFigure* fig = _objects[i];

		if (fig && typeid(*fig) == *type) {
			bool isCollision = checkCollision(fig, obj);

			if (isCollision) {
				return fig;
			}
		}
	}
	return nullptr;
}

void Manager::endGame()
{

	_score = 0;

	OOPZerebkovs::MainForm::form->endGame();

	for (int i = 0; i < MAX_OBJECTS; i++) {
		
		if (_objects[i]) {
			delete _objects[i];
			_objects[i] = nullptr;
		}
	}

	String^ result = "Your score is " + _score.ToString();

	
	MessageBox::Show(result, "Game Over", MessageBoxButtons::OKCancel, MessageBoxIcon::Information);

}

const void Manager::animate()
{
	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (_objects[i]) {
			_objects[i]->animate();
		}
	}
}

const void Manager::doCommand(Command cmd)
{
	//do command just for Hunter

	for (int i = 0; i < MAX_OBJECTS; i++) {
		if (_objects[i] && dynamic_cast<Hunter*>(_objects[i]) != NULL) {
			_objects[i]->doCommand(cmd);
			return;
		}
	}
}

const int Manager::getScore()
{
	return _score;
}

void Manager::addScore(int amount)
{
	_score += amount;
}






