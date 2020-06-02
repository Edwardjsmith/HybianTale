#include "player.h"



Player::Player(const char* filename, float x, float y, int width, int height, float scale, int framesX, int framesY, const char* tag) : Entity(filename, x, y, width, height, scale, framesX, framesY, tag)
{
	SetActive(true);
	m_attackDistance = 5.0f;

	mp_entityComponent->AddComponent<InputComponent>();
	mp_entityComponent->GetComponent<TransformComponent>().m_transformSpeed = 2.0f;
	mp_entityComponent->AddComponent<ColliderComponent>(tag);
}


Player::~Player()
{
}
