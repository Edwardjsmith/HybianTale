#pragma once
#include "entity.h"

class StateMachine;
class Enemy :
	public entity
{
public:
	Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY, entity* target);
	~Enemy();

	void update(float delta) override;
	entity* GetTarget() { return target; }

	float GetAgressionRadius() { return aggressionRadius; }

private:
	StateMachine* stateMachine;
	entity* target;

	const float aggressionRadius = 100.0f;
};

