#pragma once
#include "entity.h"
class physics
{
public:

	physics();
	~physics();

	static physics* instance();

	bool collidedLeft(entity* entA, entity* entB);
	bool collidedRight(entity* entA, entity* entB);
	bool collidedTop(entity* entA, entity* entB);
	bool collidedBottom(entity* entA, entity* entB);

	bool collision(entity* a, entity* b);


private:
	static physics* inst;

};

