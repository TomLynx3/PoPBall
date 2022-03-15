#include "StateQueue.h"

StateQueue::StateQueue(int length)
{
	_length = length;

	_stateQueue = new CreatureState[length];

	for (int i = 0; i < length; i++) {
		_stateQueue[i] = CreatureState::NOSTATE;
	}
}

StateQueue::StateQueue()
{
	_length = 25;

	_stateQueue = new CreatureState[25];

	for (int i = 0; i < 25; i++) {
		_stateQueue[i] = CreatureState::NOSTATE;
	}
}

StateQueue::~StateQueue()
{
	delete[] _stateQueue;
}

const int StateQueue::length()
{
	return _length;
}

void StateQueue::add(CreatureState state)
{
	_stateQueue[_end++] = state;

	_end %= _length;
}

void StateQueue::remove(int index)
{
	_stateQueue[index] = CreatureState::NOSTATE;
}

CreatureState StateQueue::get()
{
	CreatureState item = _stateQueue[_start];

	_stateQueue[_start++]= CreatureState::NOSTATE;

	_start %= _length;
	
	return item;
}

