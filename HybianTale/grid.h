#pragma once
class entity;
class grid
{
public:
	grid() 
	{
		for (int i = 0; i < NUM_CELLSX; i++)
		{
			for (int j = 0; j < NUM_CELLSY; j++)
			{
				cells[i][j] = nullptr;
			}
		}
	};
	~grid() 
	{
		for (int i = 0; i < NUM_CELLSX; i++)
		{
			for (int j = 0; j < NUM_CELLSY; j++)
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

	static const int CELL_SIZE = 10;
	static const int NUM_CELLSX = 68;
	static const int NUM_CELLSY = 50;

	entity* cells[NUM_CELLSX][NUM_CELLSY];

};
