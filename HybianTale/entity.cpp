#include "entity.h"


Entity::Entity(const char* filename, float x, float y, int width, int height, int framesX, int framesY, const char* tag) : m_spriteWidth(width), m_spriteHeight(height)
{
	m_tag = tag;

	m_position.x = x;
	m_position.y = y;

	m_entityTexture = TextureManager::Instance()->load(filename, TextureManager::Instance()->GetRenderer());

	SDL_QueryTexture(m_entityTexture, NULL, NULL, &m_textureWidth, &m_textureHeight);

	m_framesX = framesX;
	m_framesY = framesY;

	m_frameWidth = m_textureWidth / m_framesX;
	m_frameHeight = m_textureHeight / m_framesY; 

	m_srcRect.w = m_frameWidth;
	m_srcRect.h = m_frameHeight;
	m_srcRect.x = 0;
	m_srcRect.y = 0;

	m_destRect.x = (int)m_position.x;
	m_destRect.y = (int)m_position.y;
	m_destRect.w = m_srcRect.w * 2;
	m_destRect.h = m_srcRect.h * 2;
}


Entity::~Entity()
{
}

void Entity::Render(SDL_Renderer* rend)
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

	SDL_Rect draw{(int)m_position.x, (int)m_position.y, m_destRect.w, m_destRect.h };
	SDL_RenderCopyEx(rend, m_entityTexture, &m_srcRect, &draw, 0, 0, flip);
}

void Entity::Update(float delta)
{
	m_delta = delta;

	if (m_knockedBack)
	{
		m_knockBackTimer += m_delta;

		if (m_knockBackTimer >= 1.0f)
		{
			m_knockBackTimer = 0.0f;
			m_knockedBack = false;
			m_disableInput = false;
		}
	}
}


void Entity::MoveX(float x, bool flip)
{
	m_flipTexture = flip;
	m_srcRect.y = 0;
	m_srcRect.x = m_frameWidth * int(((SDL_GetTicks() / FPS) % m_framesX));
	mp_currentPartition->MoveEntity(this, GetX() + x * m_delta, GetY());
	mp_currentPartition->HandleCell(this);
}


void Entity::MoveY(float y, bool flip)
{
	if (flip)
	{
		m_srcRect.y = 16;
	}
	else
	{
		m_srcRect.y = m_frameHeight * 2;
	}

	m_srcRect.x = m_frameWidth * int(((SDL_GetTicks() / FPS) % m_framesX));
	mp_currentPartition->MoveEntity(this, GetX(), GetY() + y * m_delta);
	mp_currentPartition->HandleCell(this);
}

void Entity::SetX(float x)
{
	m_position.x = x;
}

void Entity::SetY(float y)
{
	m_position.y = y;
}


void Entity::KnockBack()
{
	m_disableInput = true;
	m_knockedBack = true;
}

float Entity::GetSpeed()
{
	return m_speed;
}

SpacialPartition * Entity::GetPartition()
{
	return mp_currentPartition;
}

void Entity::SetPartition(SpacialPartition * part)
{
	mp_currentPartition = part;
	mp_currentPartition->Add(this);
}

void Entity::SetActive(bool active)
{
	m_active = active;
}

bool Entity::IsActive()
{
	return m_active;
}

void Entity::SetPosition(Vector2 pos)
{
	m_position = pos;
}

int Entity::GetFrameWidth()
{
	return m_frameWidth;
}

int Entity::GetFrameHeight()
{
	return m_frameHeight;
}

float Entity::GetRight()
{
	return GetX() + (m_destRect.w);
}

float Entity::GetBottom()
{
	return GetY() + (m_destRect.h);
}

float Entity::GetAttackDistance()
{
	return m_attackDistance;
}

