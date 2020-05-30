#pragma once
#include "Enemy.h"
#include <vector>
class player;
class objectPool
{
public:
	~objectPool();
	static objectPool* instance();

	entity* getPooledTerrain(std::string tag);
	entity* getPooledEnemy(std::string tag);

	std::vector<entity*> getActiveEnemies() { return m_enemies; }
	std::vector<entity*> getActiveTerrain() { return m_terrain; }

	void fillPool(player* target);

private:
	objectPool();
	static objectPool* inst;

	std::vector<entity*> m_enemies;
	std::vector<entity*> m_terrain;

	entity* spawnEntity(const char* tag, player* target);

};

