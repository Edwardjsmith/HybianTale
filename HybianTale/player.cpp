#include "player.h"



player::player(const char* filename, float x, float y, int width, int height, int framesX, int framesY) : entity(filename, x, y, width, height, framesX, framesY)
{
	setSpeed(2.0f);
	setActive(true);
	tag = "player";

	m_attackDistance = 5.0f;
}


player::~player()
{
}
