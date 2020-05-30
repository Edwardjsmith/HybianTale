#include "StateMachine.h"
#include "IdleState.h"
#include "MoveToPlayerState.h"
#include "Enemy.h"

StateMachine::StateMachine(Enemy* agent)
{
	enemyStates = new std::map<const char*, State*>();

	enemyStates->insert(std::pair<const char*, State*>("Idle", new IdleState(agent)));
	enemyStates->insert(std::pair<const char*, State*>("MoveToPlayer", new MoveToPlayerState(agent)));

	currentState = enemyStates->at("Idle");
}

StateMachine::~StateMachine()
{
	if (enemyStates)
	{
		for (std::map<const char*, State*>::iterator itr = enemyStates->begin(); itr != enemyStates->end(); ++itr)
		{
			delete itr->first;
			delete itr->second;
		}

		delete enemyStates;
		enemyStates = nullptr;
	}
}

void StateMachine::UpdateCurrentState()
{
	if (currentState != nullptr)
	{
		currentState->UpdateState();
	}
}

void StateMachine::PollStateChange()
{
	if (currentState != nullptr)
	{
		const char* nextState = currentState->GetTransition();

		if (nextState != nullptr)
		{
			currentState->ExitState();
			currentState = enemyStates->at(nextState);
			currentState->EnterState();
		}
	}
}

void StateMachine::AddState(const char* name, State* state)
{
	enemyStates->insert(std::pair<const char*, State*>(name, state));
}

void StateMachine::SetInitialState(const char* stateName)
{
	currentState = enemyStates->at(stateName);
}
