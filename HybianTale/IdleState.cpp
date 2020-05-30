#include "IdleState.h"

IdleState::IdleState(Enemy* agent) : State(agent)
{
	moveToEnemy = new bool();
	(*moveToEnemy) = false;

	transitions->push_back(new StateTransition("MoveToPlayer", moveToEnemy));
}

IdleState::~IdleState()
{
	State::~State();

	if (moveToEnemy)
	{
		delete moveToEnemy;
	}
}

void IdleState::EnterState()
{
	(*moveToEnemy) = false;
	printf("Entered idle\n");
}

void IdleState::UpdateState()
{
	if (grid::distance(GetAgent(), GetAgent()->GetTarget()) < GetAgent()->GetAgressionRadius())
	{
		(*moveToEnemy) = true;
	}
}

void IdleState::ExitState()
{
	printf("Left idle\n");
}
