#pragma once
#include "spacialPartition.h"
#include "player.h"
#include "objectPool.h"
#include <map>
#include <fstream>
#include <string>

class MapSection 
{
public:
	MapSection();
	~MapSection();

	void LoadSection(std::string filename);
	void UpdateSection(float delta);
	void AddEntity(Entity* ent);
	void LeaveSection();
	void EnterSection();

	void AddEnemyPos(const char* tag, Vector2 pos);

	SpacialPartition* GetPartition()
	{
		return m_partition;
	}

private:

	std::map<const char*, Vector2> m_terrain;
	std::map<const char*, Vector2> m_enemyPos;

	const int SIZE_Y = SCREEN_HEIGHT / 16;
	const int size_x = SCREEN_WIDTH / 16;

	SpacialPartition* m_partition;
};

