#pragma once
#include"grid.h"
#include "physics.h"

class spacialPartition
	: public grid
{
public:
	spacialPartition();
	~spacialPartition();

	void add(entity* ent) override;
	void handleCell(entity* ent) override;
	void moveEntity(entity* ent, float x, float y) override;
};

