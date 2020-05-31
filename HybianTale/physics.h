#pragma once
#include "entity.h"
class Physics
{
public:

	Physics();
	~Physics();

	static Physics* instance();

	bool collidedLeft(Entity* entA, Entity* entB);
	bool collidedRight(Entity* entA, Entity* entB);
	bool collidedTop(Entity* entA, Entity* entB);
	bool collidedBottom(Entity* entA, Entity* entB);

	bool collision(Entity* a, Entity* b);

private:
	static Physics* inst;
};

