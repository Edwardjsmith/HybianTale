#pragma once
#include <map>

class Enemy;
class State;
class StateMachine
{
public:

	StateMachine(Enemy* agent);
	~StateMachine();

	void UpdateCurrentState();
	void PollStateChange();

	void AddState(const char*, State* state);

	void SetInitialState(const char* stateName);

private:
	State* currentState;
	std::map<const char*, State*>* enemyStates;
};

