#include "entity.h"
#include "Components.h"

Entity::Entity(const char* filename, float x, float y, int width, int height, float scale, int framesX, int framesY, const char* tag)
{
	m_ECSManager = new EntityComponentManager();
	mp_entityComponent = m_ECSManager->AddEntity();

	mp_entityComponent->AddComponent<TransformComponent>(x, y, width, height, scale);
	mp_entityComponent->AddComponent<SpriteComponent>(filename, framesX, framesY);
	m_tag = tag;
}


Entity::~Entity()
{
	if (m_ECSManager)
	{
		delete m_ECSManager;
		m_ECSManager = nullptr;
	}
}

void Entity::Update(const float& delta)
{
	m_delta = delta;

	m_ECSManager->Draw();
	m_ECSManager->Refresh();
	m_ECSManager->Update(delta);

	if (mp_currentPartition)
	{
		mp_currentPartition->HandleCell(this);
		mp_currentPartition->TrackEntity(this);
	}
}


SpacialPartition * Entity::GetPartition()
{
	return mp_currentPartition;
}

void Entity::SetPartition(SpacialPartition * part)
{
	mp_currentPartition = part;
	mp_currentPartition->Add(this);
}

void Entity::SetActive(bool active)
{
	m_active = active;
}

bool Entity::IsActive()
{
	return m_active;
}

float Entity::GetAttackDistance()
{
	return m_attackDistance;
}

