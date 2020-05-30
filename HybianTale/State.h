#pragma once
#include "Enemy.h"
#include <list>


struct StateTransition
{
	StateTransition(const char* targetState, bool* transitionCondition)
	{
		this->targetState = targetState;
		this->transitionCondition = transitionCondition;
	}
	~StateTransition(){}

	bool* transitionCondition;
	const char* targetState;
};

class State
{
public:
	State(Enemy* agent) 
	{ 
		this->agent = agent; 
		transitions = new std::list<StateTransition*>(); 
	}
	~State() 
	{ 
		if (transitions)
		{
			delete transitions;
			transitions = nullptr;
		}
	}

	std::list<StateTransition*>* transitions;

	virtual void EnterState() = 0;
	virtual void UpdateState() = 0;
	virtual void ExitState() = 0;

	const char* GetTransition() 
	{
		for (std::list<StateTransition*>::iterator itr = transitions->begin(); itr != transitions->end(); ++itr)
		{
			bool* transition = (*itr)->transitionCondition;
			if ((*transition))
			{
				return (*itr)->targetState;
			}
		}

		return nullptr;
	}

protected:
	Enemy* GetAgent() { return agent; }
private:
	Enemy* agent;
};