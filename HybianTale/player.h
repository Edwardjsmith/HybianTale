#pragma once
#include "entity.h"
class player : public entity
{
public:
	player(const char* filename, float x, float y, int width, int height, int framesX, int framesY);
	~player();
};

