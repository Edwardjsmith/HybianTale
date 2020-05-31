#include "player.h"



Player::Player(const char* filename, float x, float y, int width, int height, int framesX, int framesY, const char* tag) : Entity(filename, x, y, width, height, framesX, framesY, tag)
{
	SetSpeed(2.0f);
	SetActive(true);
	m_attackDistance = 5.0f;
}


Player::~Player()
{
}
