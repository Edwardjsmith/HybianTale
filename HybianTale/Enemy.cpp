#include "Enemy.h"
#include "StateMachine.h"


Enemy::Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY, entity* target) : entity(filename, x, y, width, height, framesX, framesY)
{
	this->target = target;
	stateMachine = new StateMachine(this);
	setSpeed(1.0f);
	setActive(true);

	tag = "enemy1";
}


Enemy::~Enemy()
{
	if (stateMachine)
	{
		delete stateMachine;
		stateMachine = nullptr;
	}
}

void Enemy::update(float delta)
{
	entity::update(delta);

	stateMachine->UpdateCurrentState();
	stateMachine->PollStateChange();
}
