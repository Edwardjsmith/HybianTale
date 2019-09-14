#include "world.h"
world::world(SDL_Renderer* Renderer)
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			m_map[i][j] = new mapSection();

			std::string file = "Art/0.txt";
			m_map[i][j]->loadSection(file, Renderer);
		}
	}

	objectPool::instance()->fillPool();
	m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
	m_currentSection->enterSection();
	m_Player = new player("Art/hero.png", 0, 0, 16, 16, 3, 4);
	m_currentSection->addEntity(m_Player);
	m_input = new input();
}
world::~world()
{
	for (int i = 0; i < WORLD_SIZE; i++)
	{
		for (int j = 0; j < WORLD_SIZE; j++)
		{
			delete m_map[i][j];
			m_map[i][j] = nullptr;
		}
	}

	if (m_Player)
	{
		delete m_Player;
		m_Player = nullptr;
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

void world::update(SDL_Renderer* rend, float delta, SDL_Event event)
{
	m_Player->update(delta);
	m_command = m_input->updateInput(event);

	if (m_command) //If input detected, execute it.
	{
		m_command->execute(*m_Player);
		checkSection(); //Only check to change section if we move
	}

	m_currentSection->updateSection(delta, rend); //Updates every entity in current section
	m_Player->render(rend); //Render player
}

//Checks to see if player has left boundaries of screen and changes section
void world::checkSection()
{
	if (m_Player->getX() < 0)
	{
		changeSectionX(false); //If we want to decrement current section (move left in world) false, else true to go right. Same logic for up and down
	}
	else if (m_Player->getX() > SCREEN_WIDTH)
	{
		changeSectionX(true);
	}
	else if (m_Player->getY() < 0)
	{
		changeSectionY(false);
	}
	else if (m_Player->getY() > SCREEN_HEIGHT)
	{
		changeSectionY(true);
	}
}

void world::changeSectionY(bool increment)
{
	if (increment == true)
	{
		m_currentWorldY++;
		m_Player->setY(0);
	}
	else
	{
		m_currentWorldY--;
		m_Player->setY(SCREEN_HEIGHT);
	}

	m_currentSection->leaveSection();
	m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
	m_currentSection->enterSection();
	m_currentSection->addEntity(m_Player);
}

void world::changeSectionX(bool increment)
{
	if (increment == true)
	{
		m_currentWorldX++;
		m_Player->setX(0);
	}
	else
	{
		m_currentWorldX--;
		m_Player->setX(SCREEN_WIDTH);
	}

	m_currentSection->leaveSection();
	m_currentSection = m_map[m_currentWorldX][m_currentWorldY];
	m_currentSection->enterSection();
	m_currentSection->addEntity(m_Player);
}

