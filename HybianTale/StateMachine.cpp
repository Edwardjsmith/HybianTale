#include "StateMachine.h"
#include "IdleState.h"
#include "MoveToPlayerState.h"
#include "Enemy.h"

StateMachine::StateMachine(Enemy* agent)
{
	m_enemyStates = new std::map<const char*, State*>();

	m_enemyStates->insert(std::pair<const char*, State*>("Idle", new IdleState(agent)));
	m_enemyStates->insert(std::pair<const char*, State*>("MoveToPlayer", new MoveToPlayerState(agent)));

	mp_currentState = m_enemyStates->at("Idle");
}

StateMachine::~StateMachine()
{
	if (m_enemyStates)
	{
		for (std::map<const char*, State*>::iterator itr = m_enemyStates->begin(); itr != m_enemyStates->end(); ++itr)
		{
			delete itr->first;
			delete itr->second;
		}

		delete m_enemyStates;
		m_enemyStates = nullptr;
	}
}

void StateMachine::UpdateCurrentState()
{
	if (mp_currentState != nullptr)
	{
		mp_currentState->UpdateState();
	}
}

void StateMachine::PollStateChange()
{
	if (mp_currentState != nullptr)
	{
		const char* nextState = mp_currentState->GetTransition();

		if (nextState != nullptr)
		{
			mp_currentState->ExitState();
			mp_currentState = m_enemyStates->at(nextState);
			mp_currentState->EnterState();
		}
	}
}

void StateMachine::AddState(const char* name, State* state)
{
	m_enemyStates->insert(std::pair<const char*, State*>(name, state));
}

void StateMachine::SetInitialState(const char* stateName)
{
	mp_currentState = m_enemyStates->at(stateName);
}
