#pragma once
#include "Enemy.h"
#include <vector>
class Player;
class ObjectPool
{
public:
	~ObjectPool();
	static ObjectPool* Instance();

	Entity* getPooledTerrain(std::string tag);
	Entity* GetPooledEnemy(std::string tag);

	std::vector<Entity*> GetActiveEnemies() { return m_enemies; }
	std::vector<Entity*> GetActiveTerrain() { return m_terrain; }

	void fillPool(Player* target);

private:
	ObjectPool();
	static ObjectPool* inst;

	std::vector<Entity*> m_enemies;
	std::vector<Entity*> m_terrain;

	Entity* SpawnEntity(const char* tag, Player* target);

};

