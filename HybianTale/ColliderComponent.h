#pragma once
#include "Components.h"
class ColliderComponent :
	public Component
{
public:
	SDL_Rect m_collider;
	const char* m_tag;

	ColliderComponent(const char* tag)
	{
		m_tag = tag;
	}

	void Init() override
	{
		if (!entity->HasComponent<TransformComponent>())
		{
			entity->AddComponent<TransformComponent>();
		}
		m_transformComponent = &entity->GetComponent<TransformComponent>();
	}

	void Update() override 
	{
		m_collider.x = m_transformComponent->m_position.x;
		m_collider.y = m_transformComponent->m_position.y;
		m_collider.w = m_transformComponent->m_width;
		m_collider.h = m_transformComponent->m_height;
	}

private:
	TransformComponent* m_transformComponent;
};

