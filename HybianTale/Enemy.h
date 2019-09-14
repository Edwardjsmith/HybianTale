#pragma once
#include "entity.h"
class Enemy :
	public entity
{
public:
	Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY);
	~Enemy();
};

