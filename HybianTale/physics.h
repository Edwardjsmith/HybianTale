#pragma once
#include "entity.h"
class Physics
{
public:

	Physics();
	~Physics();

	static Physics* instance();


private:
	static Physics* inst;
};

