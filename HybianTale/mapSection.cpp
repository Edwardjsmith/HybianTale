#include "mapSection.h"



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

void MapSection::LoadSection(std::string filename)
{
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
	m_enemyPos.insert(std::pair<const char*, Vector2>(tag, pos));
}


