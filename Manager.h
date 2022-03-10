#pragma once
#include "IFigure.h"
#include "Star.h"
#include "Square.h"
#include "Ball.h"
#include "Triangle.h"

#define MAX_OBJECTS 25
#define FIGURE_TYPE_COUNT 4


enum FigureType {BALL,STAR,TRIANGLE,RECTANGLE};
class Manager
{
private:
	IFigure* _objects[MAX_OBJECTS];
	int _frameWidth, _frameHeight;
	bool checkCollision(IFigure* first, IFigure* second);	

public:
	Manager(int frameWidth, int frameHeight);
	~Manager();
	void add(IFigure* object);
	void drawFrame(Graphics^ graphics);
	void move();
	IFigure* search(Coordinates coord);
	void remove(IFigure* object);
	void increaseSpeed();
	void decreaseSpeed();
	IFigure* createRandomFigure(int frameWidth,int frameHeight,int x,int y);
	
	
};

extern Manager* manager;