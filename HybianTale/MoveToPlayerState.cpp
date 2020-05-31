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
	if (Vector2::Distance(GetAgent()->GetPosition(), GetAgent()->GetTarget()->GetPosition()) > GetAgent()->GetAgressionRadius())
	{
		(*lostPlayer) = true;
	}

	if (GetAgent()->GetX() < GetAgent()->GetTarget()->GetX())
	{
		GetAgent()->MoveX(GetAgent()->GetSpeed(), true);
	}
	if(GetAgent()->GetX() > GetAgent()->GetTarget()->GetX())
	{
		GetAgent()->MoveX(-GetAgent()->GetSpeed(), false);
	}
	if (GetAgent()->GetY() < GetAgent()->GetTarget()->GetY())
	{
		GetAgent()->MoveY(GetAgent()->GetSpeed(), false);
	}
	if (GetAgent()->GetY() > GetAgent()->GetTarget()->GetY())
	{
		GetAgent()->MoveY(-GetAgent()->GetSpeed(), true);
	}
}

void MoveToPlayerState::ExitState()
{
	printf("Left MoveToPlayer\n");
}
