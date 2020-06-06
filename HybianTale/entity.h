#pragma once
#include "textureManager.h"
#include "defines.h"
#include "spacialPartition.h"
#include "Components.h"

class Entity
{
	friend class SpacialPartition;
public:
	Entity(const char* filename, float x, float y, int width, int height, float scale, const char* tag);
	~Entity();

	virtual void Update(const float& delta);

	SpacialPartition* GetPartition();
	void SetPartition(SpacialPartition* part);

	void SetActive(bool active);
	bool IsActive();
	float GetAttackDistance();

	const char* GetTag() { return m_tag; }

	template<typename T> T& GetComponent() const
	{
		return mp_entityComponent->GetComponent<T>();
	}

	template<typename T> bool HasComponent() const
	{
		return mp_entityComponent->HasComponent<T>();
	}

protected:
	float m_attackDistance = 0.0f;
	const char* m_tag;
	EntityComponent* mp_entityComponent;
private:

	bool m_hasCollided = false;

	SpacialPartition* mp_currentPartition = nullptr;
	bool m_active = false;

	Entity* mp_next = nullptr;
	Entity* mp_prev = nullptr;

	EntityComponentManager* m_ECSManager;

	float m_delta = 0.0f;
};

