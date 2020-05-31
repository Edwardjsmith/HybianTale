#pragma once
#include "entity.h"

class StateMachine;
class Enemy :
	public Entity
{
public:
	Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY, const char* tag, Entity* target);
	~Enemy();

	void Update(float delta) override;
	Entity* GetTarget() { return mp_target; }

	float GetAgressionRadius() { return m_aggressionRadius; }

private:
	StateMachine* mp_stateMachine;
	Entity* mp_target;

	const float m_aggressionRadius = 100.0f;
};

