#include "player.h"



Player::Player(const char* filename, float x, float y, int width, int height, float scale, const char* tag) : Entity(filename, x, y, width, height, scale, tag)
{
	SetActive(true);
	m_attackDistance = 5.0f;

	mp_entityComponent->AddComponent<InputComponent>();
	mp_entityComponent->GetComponent<TransformComponent>().m_transformSpeed = 2.0f;
	mp_entityComponent->AddComponent<ColliderComponent>(tag);

	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("idleDown", 2, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("idleUp", 1, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("idleSide", 0, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("moveDown", 2, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("moveUp", 1, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().AddAnimation("moveSide", 0, 3, 100);
	mp_entityComponent->GetComponent<SpriteComponent>().PlayAnimation("idleDown");

}


Player::~Player()
{
}
