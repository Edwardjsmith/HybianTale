#include "spacialPartition.h"
#include "entity.h"
#include "Collision.h"


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
	int cellX = (int)(ent->GetComponent<TransformComponent>().m_position.x / CELL_SIZE);
	int cellY = (int)(ent->GetComponent<TransformComponent>().m_position.y / CELL_SIZE);

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
	while(entity1 != nullptr && entity1->HasComponent<ColliderComponent>())
	{
		//Set entity2 to what is next in the grid in entity
		Entity* entity2 = entity1->mp_next;

		while(entity2 != nullptr && entity2->HasComponent<ColliderComponent>())
		{
			if (Collision::AABB(entity1->GetComponent<ColliderComponent>().m_collider, entity2->GetComponent<ColliderComponent>().m_collider))
			{
				printf("Collision!");
				if (entity1->m_tag == "player")
				{
					entity1->GetComponent<TransformComponent>().m_velocity.x *= -1;
					entity1->GetComponent<TransformComponent>().m_velocity.y *= -1;
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

void SpacialPartition::TrackEntity(Entity * entity)
{
	DBG_ASSERT(entity);

	//Checks what cell the player is in
	int oldCellX = ((int)entity->GetComponent<TransformComponent>().m_oldPosition.x / CELL_SIZE);
	int oldCellY = ((int)entity->GetComponent<TransformComponent>().m_oldPosition.y / CELL_SIZE);

	//Checks the cell the player is moving to
	int cellX = (int)(entity->GetComponent<TransformComponent>().m_position.x / CELL_SIZE);
	int cellY = (int)((int)entity->GetComponent<TransformComponent>().m_position.y / CELL_SIZE);

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

