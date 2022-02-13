#pragma once
#include "IShape.h"


#define MAX_OBJECTS 25
class Manager
{
private:
	IShape* _objects[MAX_OBJECTS];
	int _frameWidth, _frameHeight;
	bool checkCollision(IShape* first, IShape* second);
	

public:
	Manager(int frameWidth, int frameHeight);
	~Manager();
	void add(IShape* object);
	ShapeInitParams createRandomObjectParams(int x, int y);
	void drawFrame(Graphics^ graphics);
	void move();
	IShape* search(Coordinates coord);
	void remove(IShape* object);
	void increaseSpeed();
	void decreaseSpeed();
	
};

extern Manager* manager;