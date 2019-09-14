#include "objectPool.h"

objectPool* objectPool::inst = nullptr;

void objectPool::fillPool()
{
	for (int i = 0; i < MAX_POP; i++)
	{
		m_enemies.push_back(spawnEntity("enemy1"));
	}
}

objectPool::objectPool()
{
	
}

entity * objectPool::spawnEntity(const char * tag)
{
	entity* ent;
	if (tag == "enemy1")
	{
		ent = new Enemy("Art/Goblin.bmp", 0, 0, 32, 32, 1, 1);
		ent->setActive(false);
		return ent;
	}

	return nullptr;
}


objectPool::~objectPool()
{

	for (entity* ent : m_enemies)
	{
		delete ent;
		ent = nullptr;
	}
	for (entity* ent : m_enemies)
	{
		delete ent;
		ent = nullptr;
	}
}

objectPool * objectPool::instance()
{
	if (inst == nullptr)
	{
		inst = new objectPool();
	}
	return inst;
}

entity* objectPool::getPooledTerrain(std::string tag)
{
	for (entity* ent : m_terrain)
	{
		if (ent->tag == tag && !ent->isActive())
		{
			ent->setActive(true);
			return ent;
		}
	}

	return nullptr;
}

entity* objectPool::getPooledEnemy(std::string tag)
{
	for (entity* ent : m_enemies)
	{
		if (ent->tag == tag && ent->isActive() == false)
		{
			ent->setActive(true);
			return ent;
		}
	}

	return nullptr;
}
