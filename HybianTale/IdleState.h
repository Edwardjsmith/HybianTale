#pragma once
#include "State.h"
#include "Enemy.h"

class IdleState :
	public State
{
public:
	IdleState(Enemy* agent);
	~IdleState();

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override;

private:
	bool* moveToEnemy;
};

