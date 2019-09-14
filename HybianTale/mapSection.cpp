#include "mapSection.h"



mapSection::mapSection()
{
	partition = new spacialPartition();
}


mapSection::~mapSection()
{
	if (partition)
	{
		delete partition;
		partition = nullptr;
	}

	for (std::map<const char*, Vector2>::iterator itr = enemyPos.begin(); itr != enemyPos.end(); itr++)
	{
		delete itr->first;
	}

	for (std::map<const char*, Vector2>::iterator itr = terrain.begin(); itr != terrain.end(); itr++)
	{
		delete itr->first;
	}

	enemyPos.clear();
	terrain.clear();
}

void mapSection::loadSection(std::string filename, SDL_Renderer * ren)
{
	char tile;
	std::fstream map;

	map.open(filename);

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			map >> tile;

			switch (tile)
			{
			case '0': 
				break;
			case '1': 
				addEnemyPos("enemy1", Vector2(i*16,j*16));
				break;
			case '2': 
				break;
			case '3': 
				break;
			}
		}
	}
	map.close();
}

void mapSection::updateSection(float delta, SDL_Renderer * ren)
{
	for (entity* ent : objectPool::instance()->getActiveEnemies())
	{
		if (ent->isActive())
		{
			ent->update(delta);
			ent->render(ren);
		}
	}
	for (entity* ent : objectPool::instance()->getActiveTerrain())
	{
		if (ent->isActive())
		{
			ent->update(delta);
			ent->render(ren);
		}
	}
}

void mapSection::addEntity(entity * ent)
{
	ent->setPartition(partition);
}

void mapSection::leaveSection()
{
	for (entity* ent : objectPool::instance()->getActiveEnemies())
	{
		if (ent->isActive())
		{
			ent->setActive(false);
			ent->setPos(ent->zero);
		}
	}
	for (entity* ent : objectPool::instance()->getActiveTerrain())
	{
		if (ent->isActive())
		{
			ent->setActive(false);
			ent->setPos(ent->zero);
		}
	}
}

void mapSection::enterSection()
{
	std::map<const char*, Vector2>::iterator it;

	for (it = enemyPos.begin(); it != enemyPos.end(); it++)
	{
		objectPool::instance()->getPooledEnemy(it->first)->setPos(it->second);
	}

	for (entity* ent : objectPool::instance()->getActiveEnemies())
	{
		if (ent->isActive())
		{
			addEntity(ent);
		}
	}
	for (entity* ent : objectPool::instance()->getActiveTerrain())
	{
		if (ent->isActive())
		{
			addEntity(ent);
		}
	}
}

void mapSection::addEnemyPos(const char * tag, Vector2 pos)
{
	enemyPos.insert(std::pair<const char*, Vector2>(tag, pos));
}


