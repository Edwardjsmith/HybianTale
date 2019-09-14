#include "spacialPartition.h"
#include "entity.h"


spacialPartition::spacialPartition() : grid()
{
}


spacialPartition::~spacialPartition() 
{
	grid::~grid();
}

void spacialPartition::add(entity* ent)
{
	//Determine which cell the entity is in
	int cellX = (int)(ent->getX() / CELL_SIZE);
	int cellY = (int)(ent->getY() / CELL_SIZE);


	//Adds the entity to the front of the list of entitities
	if (ent->prev)
	{
		ent->prev = NULL;
	}
	ent->next = cells[cellX][cellY];
	cells[cellX][cellY] = ent;

	if (ent->next != NULL)
	{
		ent->next->prev = ent;
	}
}

void spacialPartition::handleCell(entity * ent)
{
	while (ent != nullptr)
	{
		//Set entity2 to what is next in the grid in entity
		entity* entity2 = ent->next;

		while (entity2 != nullptr)
		{
			//Checks for collision of each object in a cell as well as distance
			//Uses the tag system to differentiate between entities
			//Then returns true or false depending collision so 
			//collision can be handled elsewhere such as player input function or enemy movement

			if (entity2->tag == "enemy1")
			{

			}

			//Entity2 now points to the next in the list of current cell
			printf("point ent2 at next in grid start \n");
			entity2 = entity2->next;
			printf("point ent2 at next in grid end\n");
		}
		//Same again here for entity
		printf("point ent at next in grid start \n");
		ent = ent->next;
		printf("point ent at next in grid end\n");
	}
	printf("End handlecell..\n");
}

void spacialPartition::moveEntity(entity * ent, float x, float y)
{
	DBG_ASSERT(ent);
	//Store old pos to revert back to on collision
	ent->m_oldPosition.x = ent->getX();
	ent->m_oldPosition.y = ent->getY();

	//Checks what cell the player is in
	int oldCellX = ((int)ent->getX() / CELL_SIZE);
	int oldCellY = ((int)ent->getY() / CELL_SIZE);

	//Checks the cell the player is moving to
	int cellX = (int)(x / CELL_SIZE);
	int cellY = (int)(y / CELL_SIZE);

	//Move entity
	ent->setX(x);
	ent->setY(y);


	//If the entity is still in the same cell, break
	if (oldCellX == cellX && oldCellY == cellY)
	{
		return;
	}

	//unlink from the old cells list of entities
	if (ent->prev != NULL)
	{
		ent->prev->next = ent->next;
	}

	if (ent->next != NULL)
	{
		ent->next->prev = ent->prev;
	}

	//If it was at the head of that list remove
	if (cells[oldCellX][oldCellY] == ent)
	{
		cells[oldCellX][oldCellY] = ent->next;
	}

	//add it to the new cell
	DBG_ASSERT(ent);
	add(ent);
}

