#include "objectPool.h"
#include "player.h"

ObjectPool* ObjectPool::inst = nullptr;

void ObjectPool::fillPool(Player* target)
{
	for (int i = 0; i < MAX_POP; i++)
	{
		m_enemies.push_back(SpawnEntity("enemy1", target));
	}
}

ObjectPool::ObjectPool()
{
	
}

Entity * ObjectPool::SpawnEntity(const char * tag, Player* target)
{
	Entity* ent;
	if (tag == "enemy1")
	{
		ent = new Enemy("Art/hero.png", 0, 0, 16, 16, 3, 4, 2, tag, target);
		ent->SetActive(false);
		return ent;
	}

	return nullptr;
}


ObjectPool::~ObjectPool()
{

	for (Entity* ent : m_enemies)
	{
		delete ent;
		ent = nullptr;
	}
	for (Entity* ent : m_enemies)
	{
		delete ent;
		ent = nullptr;
	}

	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}

ObjectPool * ObjectPool::Instance()
{
	if (inst == nullptr)
	{
		inst = new ObjectPool();
	}
	return inst;
}

Entity* ObjectPool::getPooledTerrain(std::string tag)
{
	for (Entity* ent : m_terrain)
	{
		if (ent->GetTag() == tag && !ent->IsActive())
		{
			ent->SetActive(true);
			return ent;
		}
	}

	return nullptr;
}

Entity* ObjectPool::GetPooledEnemy(std::string tag)
{
	for (Entity* ent : m_enemies)
	{
		if (ent->GetTag() == tag && ent->IsActive() == false)
		{
			ent->SetActive(true);
			return ent;
		}
	}

	return nullptr;
}
