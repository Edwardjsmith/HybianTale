#pragma once
#include "spacialPartition.h"
#include "player.h"
#include "objectPool.h"
#include <map>
#include <fstream>
#include <string>
#include "Tile.h"

struct tilecoord;

class MapSection 
{
public:
	std::vector<tilecoord> tile_map;
	MapSection();
	~MapSection();
	std::string tilepackurl = "Art/tilesprites.bmp";

	void LoadSection(std::string filename, int offsetx, int offsety);

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

	std::multimap<const char*, Vector2> m_terrain;
	std::multimap<const char*, Vector2> m_enemyPos;
	std::vector<Tile*> tiles;
	const int SCALE = 32;
	const int SIZE_Y = SCREEN_HEIGHT / SCALE;
	const int SIZE_X = SCREEN_WIDTH / SCALE;

	SpacialPartition* m_partition;


	void addtile(int x, int y, int id);
};

