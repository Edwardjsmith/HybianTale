#pragma once
#include "mapSection.h"
#include "input.h"
class world
{
public:
	world(SDL_Renderer* Renderer);
	~world();

	void update(SDL_Renderer* rend, float delta, SDL_Event event);
	bool boundsCheck(int index);
	
	mapSection* m_map[WORLD_SIZE][WORLD_SIZE];
	mapSection* m_currentSection;

private:

	void checkSection();
	void changeSectionX(bool increment);
	void changeSectionY(bool increment);

	input* m_input;
	command* m_command;
	player* m_Player;

	int m_currentWorldX = 0;
	int m_currentWorldY = 0;

};

