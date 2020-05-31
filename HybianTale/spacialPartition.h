#pragma once
#include"grid.h"
#include "physics.h"

class SpacialPartition
	: public Grid
{
public:
	SpacialPartition();
	~SpacialPartition();

	void Add(Entity* ent) override;
	void Remove(Entity* ent);
	void HandleCell(Entity* ent) override;
	void MoveEntity(Entity* ent, const float& x, const float& y) override;
};

