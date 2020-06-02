#include "world.h"
World::World()
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			m_map[i][j] = new MapSection();

			std::string file = "Art/0.txt";
			m_map[i][j]->LoadSection(file);
		}
	}

	m_player = new Player("Art/hero.png", 0, 0, 16, 16, 3, 4, 2, "player");
	ObjectPool::Instance()->fillPool(m_player);
	m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
	m_currentSection->EnterSection();
	m_currentSection->AddEntity(m_player);
}
World::~World()
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			delete m_map[i][j];
			m_map[i][j] = nullptr;
		}
	}

	if (m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
}

void World::Update(float delta)
{
	m_player->Update(delta);
	m_currentSection->UpdateSection(delta); //Updates every entity in current section
}

bool World::BoundsCheck(int index)
{
	if (index > WORLD_SIZE)
	{
		return false;
	}
	else if (index < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Checks to see if player has left boundaries of screen and changes section
void World::CheckSection()
{
	if (m_player->GetComponent<TransformComponent>().m_position.x < 0)
	{
		ChangeSectionX(false); //If we want to decrement current section (move left in world) false, else true to go right. Same logic for up and down
	}
	else if (m_player->GetComponent<TransformComponent>().m_position.y > SCREEN_WIDTH)
	{
		ChangeSectionX(true);
	}
	else if (m_player->GetComponent<TransformComponent>().m_position.x < 0)
	{
		ChangeSectionY(false);
	}
	else if (m_player->GetComponent<TransformComponent>().m_position.y > SCREEN_HEIGHT)
	{
		ChangeSectionY(true);
	}
}

void World::ChangeSectionY(bool increment)
{
	bool bounds = false;
	float oldPosY = 0.0f;
	if (increment == true )
	{
		bounds = BoundsCheck(m_currentWorldY + 1);
		oldPosY = SCREEN_HEIGHT;

		if (bounds)
		{
			m_currentWorldY++;
			m_player->GetComponent<TransformComponent>().m_position.y = 0;
		}
	}
	else
	{
		bounds = BoundsCheck(m_currentWorldY - 1);
		oldPosY = 0;

		if (bounds)
		{
			m_currentWorldY--;
			m_player->GetComponent<TransformComponent>().m_position.y = SCREEN_HEIGHT;
		}
	}

	if (bounds)
	{
		m_currentSection->LeaveSection();
		m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
		m_currentSection->EnterSection();
		m_currentSection->AddEntity(m_player);
	}
	else
	{
		m_player->GetComponent<TransformComponent>().m_position.y = oldPosY;
	}
}

void World::ChangeSectionX(bool increment)
{
	bool bounds = false;
	float oldPosX = 0.0f;
	if (increment == true)
	{
		bounds = BoundsCheck(m_currentWorldX + 1);
		oldPosX = SCREEN_WIDTH;

		if (bounds)
		{
			m_currentWorldX++;
			m_player->GetComponent<TransformComponent>().m_position.x = 0;
		}
	}
	else
	{
		bounds = BoundsCheck(m_currentWorldX - 1);
		oldPosX = 0;

		if (bounds)
		{
			m_currentWorldX--;
			m_player->GetComponent<TransformComponent>().m_position.x = SCREEN_WIDTH;
		}
	}

	if (bounds)
	{
		m_currentSection->LeaveSection();
		m_currentSection->GetPartition()->Remove(m_player);
		m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
		m_currentSection->EnterSection();
		m_currentSection->AddEntity(m_player);
	}
	else
	{
		m_player->GetComponent<TransformComponent>().m_position.x = oldPosX;
	}
}

