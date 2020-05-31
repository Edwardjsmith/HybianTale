#include "spacialPartition.h"
#include "entity.h"


SpacialPartition::SpacialPartition() : Grid()
{
}


SpacialPartition::~SpacialPartition() 
{
	Grid::~Grid();
}

void SpacialPartition::Add(Entity* ent)
{
	//Determine which cell the entity is in
	int cellX = (int)(ent->GetX() / CELL_SIZE);
	int cellY = (int)(ent->GetY() / CELL_SIZE);

	//Adds the entity to the front of the list of entitities
	if (ent->mp_prev)
	{
		ent->mp_prev = NULL;
	}
	ent->mp_next = m_cells[cellX][cellY];
	m_cells[cellX][cellY] = ent;

	if (ent->mp_next != NULL)
	{
		ent->mp_next->mp_prev = ent;
	}
}

void SpacialPartition::Remove(Entity * ent)
{
	for (int i = 0; i < NUM_CELLS; i++)
	{
		for (int j = 0; j < NUM_CELLS; j++)
		{
			m_cells[i][j] = nullptr;
		}
	}


}

void SpacialPartition::HandleCell(Entity * entity1)
{
	while(entity1 != nullptr)
	{
		//Set entity2 to what is next in the grid in entity
		Entity* entity2 = entity1->mp_next;

		while(entity2 != nullptr)
		{
			{
				if (Physics::instance()->collision(entity1, entity2))
				{
					printf("Collided\n");
					entity1->SetPosition(entity1->m_oldPosition);
				}
			}

			//Entity2 now points to the next in the list of current cell
			//printf("point ent2 at next in grid start \n");
			entity2 = entity2->mp_next;
			//printf("point ent2 at next in grid end\n");
		}
		//Same again here for entity
		//printf("point ent at next in grid start \n");
		entity1 = entity1->mp_next;
		//printf("point ent at next in grid end\n");
	}
	//printf("End handlecell..\n");
}

void SpacialPartition::MoveEntity(Entity * entity, const float& x, const float& y)
{
	DBG_ASSERT(entity);
	//Store old pos to revert back to on collision
	(*entity).m_oldPosition = entity->GetPosition();

	//Checks what cell the player is in
	int oldCellX = ((int)entity->GetX() / CELL_SIZE);
	int oldCellY = ((int)entity->GetY() / CELL_SIZE);

	//Checks the cell the player is moving to
	int cellX = (int)(x / CELL_SIZE);
	int cellY = (int)(y / CELL_SIZE);

	//Move entity
	entity->SetX(x);
	entity->SetY(y);

	//If the entity is still in the same cell, break
	if (oldCellX == cellX && oldCellY == cellY)
	{
		return;
	}

	//unlink from the old cells list of entities
	if (entity->mp_prev != nullptr)
	{
		entity->mp_prev->mp_next = entity->mp_next;
	}

	if (entity->mp_next != nullptr)
	{
		entity->mp_next->mp_prev = entity->mp_prev;
	}

	//If it was at the head of that list remove
	if (m_cells[oldCellX][oldCellY] == entity)
	{
		m_cells[oldCellX][oldCellY] = entity->mp_next;
	}

	//add it to the new cell
	DBG_ASSERT(entity);
	Add(entity);
}

