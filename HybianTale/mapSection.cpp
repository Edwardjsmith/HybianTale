#include "mapSection.h"
#include "usefull_functions.h"



MapSection::MapSection()
{
	m_partition = new SpacialPartition();
}


MapSection::~MapSection()
{
	if (m_partition)
	{
		delete m_partition;
		m_partition = nullptr;
	}

	for (std::map<const char*, Vector2>::iterator itr = m_enemyPos.begin(); itr != m_enemyPos.end(); itr++)
	{
		delete itr->first;
	}

	for (std::map<const char*, Vector2>::iterator itr = m_terrain.begin(); itr != m_terrain.end(); itr++)
	{
		delete itr->first;
	}

	m_enemyPos.clear();
	m_terrain.clear();
}

void MapSection::LoadSection(std::string filename,int offsetx, int offsety)
{
	
	std::vector<std::string> map = LoadTextFile_WithSplit(filename,',');

	for (int i = 0; i < SIZE_X; i++)
	{
		for (int j = 0; j < SIZE_Y; j++)
		{
			int tile = std::stoi(map[i*SIZE_X + j]);
			switch (tile)
			{
			case -1:
				addtile(i, j, 1);
				break;
			case 0:
				addtile(i, j, 2);
				break;
			case 1:
				addtile(i, j, 2);
				break;
			case 2:
				break;
			case 3:
				break;
			}
		}
	}
	//std::vector<std::vector<int>> map_tiles = ReadBMP_Blue(filename);

	//std::vector<std::vector<int>> map_objs = ReadBMP_Green(filename);
	//std::vector<std::vector<int>> map_overlays = ReadBMP_Red(filename);




	/*
	
	char tile;
	std::fstream map;

	map.open(filename);

	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			map >> tile;

			switch (tile)
			{
			case '0': 
				break;
			case '1': 
				AddEnemyPos("enemy1", Vector2(i*32,j*32));
				break;
			case '2': 
				break;
			case '3': 
				break;
			}
		}
	}
	map.close();
	
	*/
}

void MapSection::UpdateSection(float delta)
{
	for (Entity* ent : ObjectPool::Instance()->GetActiveEnemies())
	{
		if (ent->IsActive())
		{
			ent->Update(delta);
		}
	}
	for (Entity* ent : ObjectPool::Instance()->GetActiveTerrain())
	{
		if (ent->IsActive())
		{
			ent->Update(delta);
		}
	}
	for (int i = 0; i < tiles.size(); i++) {
		tiles.at(i)->Draw();
	}
}

void MapSection::AddEntity(Entity * ent)
{
	ent->SetPartition(m_partition);
}

void MapSection::LeaveSection()
{
	for (Entity* ent : ObjectPool::Instance()->GetActiveEnemies())
	{
		if (ent->IsActive())
		{
			ent->SetActive(false);
		}
	}
	for (Entity* ent : ObjectPool::Instance()->GetActiveTerrain())
	{
		if (ent->IsActive())
		{
			ent->SetActive(false);
		}
	}
}

void MapSection::EnterSection()
{
	std::map<const char*, Vector2>::iterator it;

	for (it = m_enemyPos.begin(); it != m_enemyPos.end(); it++)
	{
		ObjectPool::Instance()->GetPooledEnemy(it->first)->GetComponent<TransformComponent>().m_position =it->second;
	}

	for (Entity* ent : ObjectPool::Instance()->GetActiveEnemies())
	{
		if (ent->IsActive())
		{
			AddEntity(ent);
		}
	}
	for (Entity* ent : ObjectPool::Instance()->GetActiveTerrain())
	{
		if (ent->IsActive())
		{
			AddEntity(ent);
		}
	}
}

void MapSection::AddEnemyPos(const char * tag, Vector2 pos)
{
	m_enemyPos.emplace(tag, pos);
}

void MapSection::addtile(int x, int y, int id)
{

	//const char* filename, int xPos, int yPos, int srcX, int srcY, int width, int height, float scale
	std::vector<tilecoord> tile_map = breakspritesheet(tilepackurl, 255, 0, 226);
	Tile * temp = new Tile(tilepackurl.c_str(),x*SCALE,y*SCALE,SCALE,SCALE,tile_map.at(id).x, tile_map.at(id).y, tile_map.at(id).width, tile_map.at(id).height);
	tiles.push_back(temp);
}


