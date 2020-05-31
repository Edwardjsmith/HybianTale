#include "world.h"
World::World(SDL_Renderer* Renderer)
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			m_map[i][j] = new MapSection();

			std::string file = "Art/0.txt";
			m_map[i][j]->LoadSection(file, Renderer);
		}
	}

	m_player = new Player("Art/hero.png", 0, 0, 16, 16, 3, 4, "player");
	ObjectPool::Instance()->fillPool(m_player);
	m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
	m_currentSection->EnterSection();
	m_currentSection->AddEntity(m_player);
	m_input = new Input();
	
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
	if (m_input)
	{
		delete m_input;
		m_input = nullptr;
	}
	if (m_command)
	{
		delete m_command;
		m_command = nullptr;
	}
}

void World::Update(SDL_Renderer* rend, float delta, SDL_Event event)
{
	m_player->Update(delta);

	if (!m_player->InputDisabled())
	{
		m_command = m_input->UpdateInput(event);
	}

	if (m_command) //If input detected, execute it.
	{
		m_command->Execute(*m_player);
		CheckSection(); //Only check to change section if we move
	}

	m_currentSection->UpdateSection(delta, rend); //Updates every entity in current section
	m_player->Render(rend); //Render player
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
	if (m_player->GetX() < 0)
	{
		ChangeSectionX(false); //If we want to decrement current section (move left in world) false, else true to go right. Same logic for up and down
	}
	else if (m_player->GetX() > SCREEN_WIDTH)
	{
		ChangeSectionX(true);
	}
	else if (m_player->GetY() < 0)
	{
		ChangeSectionY(false);
	}
	else if (m_player->GetY() > SCREEN_HEIGHT)
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
			m_player->SetY(0);
		}
	}
	else
	{
		bounds = BoundsCheck(m_currentWorldY - 1);
		oldPosY = 0;

		if (bounds)
		{
			m_currentWorldY--;
			m_player->SetY(SCREEN_HEIGHT);
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
		m_player->SetY(oldPosY);
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
			m_player->SetX(0);
		}
	}
	else
	{
		bounds = BoundsCheck(m_currentWorldX - 1);
		oldPosX = 0;

		if (bounds)
		{
			m_currentWorldX--;
			m_player->SetX(SCREEN_WIDTH);
		}
	}

	if (bounds)
	{
		m_currentSection->LeaveSection();
		m_currentSection->m_partition->Remove(m_player);
		m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
		m_currentSection->EnterSection();
		m_currentSection->AddEntity(m_player);
	}
	else
	{
		m_player->SetX(oldPosX);
	}
}

