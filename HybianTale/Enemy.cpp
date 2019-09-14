#include "Enemy.h"



Enemy::Enemy(const char* filename, float x, float y, int width, int height, int framesX, int framesY) : entity(filename, x, y, width, height, framesX, framesY)
{
	setSpeed(2.0f);
	setActive(true);

	tag = "enemy1";
}


Enemy::~Enemy()
{
}
