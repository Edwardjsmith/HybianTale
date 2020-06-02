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
	void TrackEntity(Entity* ent) override;
};

