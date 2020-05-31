#include "Enemy.h"
#include "StateMachine.h"


Enemy::Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY, const char* tag, Entity* target) : Entity(filename, x, y, width, height, framesX, framesY, tag)
{
	this->mp_target = target;
	mp_stateMachine = new StateMachine(this);
	SetSpeed(1.0f);
	SetActive(true);
}


Enemy::~Enemy()
{
	if (mp_stateMachine)
	{
		delete mp_stateMachine;
		mp_stateMachine = nullptr;
	}
}

void Enemy::Update(float delta)
{
	Entity::Update(delta);

	mp_stateMachine->UpdateCurrentState();
	mp_stateMachine->PollStateChange();
}
