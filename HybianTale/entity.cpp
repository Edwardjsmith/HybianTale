#include "entity.h"


entity::entity(const char* filename, float x, float y, int width, int height, int framesX, int framesY) : m_spriteWidth(width), m_spriteHeight(height)
{
	m_position.x = x;
	m_position.y = y;

	m_entityTexture = textureManager::instance()->load(filename, textureManager::instance()->getRenderer());

	SDL_QueryTexture(m_entityTexture, NULL, NULL, &m_textureWidth, &m_textureHeight);

	m_framesX = framesX;
	m_framesY = framesY;

	m_frameWidth = m_textureWidth / m_framesX;
	m_frameHeight = m_textureHeight / m_framesY; 

	srcRect.w = m_frameWidth;
	srcRect.h = m_frameHeight;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = (int)m_position.x;
	destRect.y = (int)m_position.y;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}


entity::~entity()
{
}

void entity::render(SDL_Renderer* rend)
{
	SDL_RendererFlip flip;

	if (m_flipTexture)
	{
		flip = SDL_FLIP_HORIZONTAL;
	}
	else
	{
		flip = SDL_FLIP_NONE;
	}

	SDL_Rect draw{(int)m_position.x, (int)m_position.y, destRect.w, destRect.h };
	SDL_RenderCopyEx(rend, m_entityTexture, &srcRect, &draw, 0, 0, flip);
}

void entity::update(float delta)
{
	m_delta = delta;

	if (knockedBack)
	{
		knockBackTimer += m_delta;

		if (knockBackTimer >= 1.0f)
		{
			knockBackTimer = 0.0f;
			knockedBack = false;
			disableInput = false;
		}
	}
}


void entity::moveX(float x, bool flip)
{
	m_flipTexture = flip;
	srcRect.y = 0;
	srcRect.x = m_frameWidth * int(((SDL_GetTicks() / FPS) % m_framesX));
	currentPartition->moveEntity(this, m_position.x + x * m_delta, getY());
	currentPartition->handleCell(this);
}


void entity::moveY(float y, bool flip)
{
	if (flip)
	{
		srcRect.y = 16;
	}
	else
	{
		srcRect.y = m_frameHeight * 2;
	}

	srcRect.x = m_frameWidth * int(((SDL_GetTicks() / FPS) % m_framesX));
	currentPartition->moveEntity(this, getX(), m_position.y + y * m_delta);
	currentPartition->handleCell(this);
}

void entity::setX(float x)
{
	m_position.x = x;
}

void entity::setY(float y)
{
	m_position.y = y;
}


void entity::knockBack()
{
	disableInput = true;
	knockedBack = true;
}

float entity::getSpeed()
{
	return m_speed;
}

spacialPartition * entity::getPartition()
{
	return currentPartition;
}

void entity::setPartition(spacialPartition * part)
{
	currentPartition = part;
	currentPartition->add(this);
}

void entity::setActive(bool active)
{
	m_active = active;
}

bool entity::isActive()
{
	return m_active;
}

void entity::setPos(Vector2 pos)
{
	m_position = pos;
}

int entity::getFrameWidth()
{
	return m_frameWidth;
}

int entity::getFrameHeight()
{
	return m_frameHeight;
}

float entity::getRight()
{
	return getX() + (destRect.w);
}

float entity::getBottom()
{
	return getY() + (destRect.h);
}

float entity::getAttackDistance()
{
	return m_attackDistance;
}

