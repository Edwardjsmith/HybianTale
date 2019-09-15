#pragma once
class entity;
class grid
{
public:
	grid() 
	{
		for (int i = 0; i < NUM_CELLS; i++)
		{
			for (int j = 0; j < NUM_CELLS; j++)
			{
				cells[i][j] = nullptr;
			}
		}
	};
	~grid() 
	{
		for (int i = 0; i < NUM_CELLS; i++)
		{
			for (int j = 0; j < NUM_CELLS; j++)
			{
				cells[i][j] = nullptr;
			}
		}
	};

	virtual void add(entity* ent) = 0; 
	virtual void handleCell(entity* ent) = 0;
	virtual void moveEntity(entity* ent, float x, float y) = 0;

	//Store old position values to revert to on collision

	float oldX;
	float oldY;

protected:

	static const int CELL_SIZE = 100;
	static const int NUM_CELLS = 10;

	entity* cells[NUM_CELLS][NUM_CELLS];

	float distance(entity * entA, entity * entB);

};
