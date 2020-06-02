#include "Enemy.h"
#include "StateMachine.h"


Enemy::Enemy(const char* filename, float x, float y, int width, int height, float scale, int framesX, int framesY, const char* tag, Entity* target) : Entity(filename, x, y, width, height, scale, framesX, framesY, tag)
{
	this->mp_target = target;
	mp_stateMachine = new StateMachine(this);
	SetActive(true);
	mp_entityComponent->GetComponent<TransformComponent>().m_transformSpeed = 1.0f;
	mp_entityComponent->AddComponent<ColliderComponent>(tag);
}


Enemy::~Enemy()
{
	if (mp_stateMachine)
	{
		delete mp_stateMachine;
		mp_stateMachine = nullptr;
	}
}

void Enemy::Update(const float& delta)
{
	Entity::Update(delta);

	mp_stateMachine->UpdateCurrentState();
	mp_stateMachine->PollStateChange();
}
