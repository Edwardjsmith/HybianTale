#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class EntityComponent;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template<typename T> inline ComponentID GetComponentTypeID() noexcept
{
	static ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	EntityComponent* entity;

	virtual void Init() {};
	virtual void Update() {};
	virtual void Update(const float& delta) {};
	virtual void Draw() {};

	virtual ~Component() {};
};

class EntityComponent
{
public:
	void Update(const float& delta)
	{
		for (auto& c : components)
		{
			c->Update();
			c->Update(delta);
		}
	}
	void Draw()
	{
		for (auto& c : components) c->Draw();
	}
	bool IsActive() const { return m_active; }
	void Destroy() { m_active = false; }

	template <typename T> bool HasComponent()
	{
		return componentBitSet[GetComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& AddComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));

		componentArray[GetComponentTypeID<T>()] = c;
		componentBitSet[GetComponentTypeID<T>()] = true;

		c->Init();

		return *c;
	}

	template<typename T> T& GetComponent() const
	{
		auto ptr(componentArray[GetComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

private:
	std::vector<std::unique_ptr<Component>> components;
	ComponentArray componentArray;
	ComponentBitSet componentBitSet;

	bool m_active = true;
};

class EntityComponentManager
{
private:
	std::vector<std::unique_ptr<EntityComponent>> entityComponents;

public:
	void Update(const float& delta)
	{
		for (auto& entComps : entityComponents)
		{
			entComps->Update(delta);
		}
	}
	void Draw()
	{
		for (auto& entComps : entityComponents)
		{
			entComps->Draw();
		}
	}

	void Refresh()
	{
		entityComponents.erase(std::remove_if(std::begin(entityComponents), std::end(entityComponents),
			[](const std::unique_ptr<EntityComponent>& mEntComp)
			{
				return !mEntComp->IsActive();
			}),
			std::end(entityComponents));
	}

	EntityComponent* AddEntity()
	{
		EntityComponent* entComp = new EntityComponent();
		std::unique_ptr<EntityComponent> uPtr{ entComp };
		entityComponents.emplace_back(std::move(uPtr));

		return entComp;
	}
};

