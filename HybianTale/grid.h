#pragma once
#include "Vector2.h"
class Entity;
class Grid
{
public:
	Grid() 
	{
		for (int i = 0; i < NUM_CELLS; i++)
		{
			for (int j = 0; j < NUM_CELLS; j++)
			{
				m_cells[i][j] = nullptr;
			}
		}
	};
	~Grid() 
	{
		for (int i = 0; i < NUM_CELLS; i++)
		{
			for (int j = 0; j < NUM_CELLS; j++)
			{
				m_cells[i][j] = nullptr;
			}
		}
	};

	virtual void Add(Entity* ent) = 0; 
	virtual void HandleCell(Entity* ent) = 0;
	virtual void TrackEntity(Entity* ent) = 0;
	
protected:

	static const int CELL_SIZE = 100;
	static const int NUM_CELLS = 10;

	Entity* m_cells[NUM_CELLS][NUM_CELLS];
};
