#pragma once
#include "Pictures.h"
class StateQueue
{
public:
	StateQueue(int length);
	StateQueue();
	~StateQueue();
	const int length();
	void add(CreatureState state);
	void remove(int index);
	CreatureState get();
	
private:
	int _length;
	int _start = 0;
	int _end =0; 
	CreatureState* _stateQueue;
};


