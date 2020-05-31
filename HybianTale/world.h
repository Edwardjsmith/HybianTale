#pragma once
#include "mapSection.h"
#include "input.h"
class World
{
public:
	World(SDL_Renderer* Renderer);
	~World();

	void Update(SDL_Renderer* rend, float delta, SDL_Event event);
	bool BoundsCheck(int index);
	
	MapSection* m_map[WORLD_SIZE][WORLD_SIZE];
	MapSection* m_currentSection;

private:

	void CheckSection();
	void ChangeSectionX(bool increment);
	void ChangeSectionY(bool increment);

	Input* m_input;
	Command* m_command;
	Player* m_player;

	int m_currentWorldX = 0;
	int m_currentWorldY = 0;

};

