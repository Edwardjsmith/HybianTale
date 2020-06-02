#pragma once
#include "entity.h"
class Player : public Entity
{
public:
	Player(const char* filename, float x, float y, int width, int height, float scale, int framesX, int framesY, const char* tag );
	~Player();
};

