#pragma once
#include "mapSection.h"

class World
{
public:
	World();
	~World();

	void Update(float delta);
	bool BoundsCheck(int index);
	
	MapSection* m_map[WORLD_SIZE][WORLD_SIZE];
	MapSection* m_currentSection;

	

private:

	void CheckSection();
	void ChangeSectionX(bool increment);
	void ChangeSectionY(bool increment);

	Player* m_player;

	int m_currentWorldX = 0;
	int m_currentWorldY = 0;

};

