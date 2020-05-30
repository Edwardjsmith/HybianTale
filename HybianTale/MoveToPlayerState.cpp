#include "MoveToPlayerState.h"

MoveToPlayerState::MoveToPlayerState(Enemy* agent) : State(agent)
{
	lostPlayer = new bool();
	(*lostPlayer) = false;

	transitions->push_back(new StateTransition("Idle", lostPlayer));
}

MoveToPlayerState::~MoveToPlayerState()
{
	State::~State();

	if (lostPlayer)
	{
		delete lostPlayer;
	}
}

void MoveToPlayerState::EnterState()
{
	printf("Entered MoveToPlayer\n");
	(*lostPlayer) = false;
}

void MoveToPlayerState::UpdateState()
{
	if (grid::distance(GetAgent(), GetAgent()->GetTarget()) > GetAgent()->GetAgressionRadius())
	{
		(*lostPlayer) = true;
	}

	if (GetAgent()->getX() < GetAgent()->GetTarget()->getX())
	{
		GetAgent()->moveX(GetAgent()->getSpeed(), true);
	}
	if(GetAgent()->getX() > GetAgent()->GetTarget()->getX())
	{
		GetAgent()->moveX(-GetAgent()->getSpeed(), false);
	}
	if (GetAgent()->getY() < GetAgent()->GetTarget()->getY())
	{
		GetAgent()->moveY(GetAgent()->getSpeed(), false);
	}
	if (GetAgent()->getY() > GetAgent()->GetTarget()->getY())
	{
		GetAgent()->moveY(-GetAgent()->getSpeed(), true);
	}
}

void MoveToPlayerState::ExitState()
{
	printf("Left MoveToPlayer\n");
}
