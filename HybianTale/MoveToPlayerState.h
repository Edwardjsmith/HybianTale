#pragma once
#include "State.h"
class MoveToPlayerState :
	public State
{
public:
	MoveToPlayerState(Enemy* agent);
	~MoveToPlayerState();

	void EnterState() override;
	void UpdateState() override;
	void ExitState() override;

private:
	bool* lostPlayer;
};

