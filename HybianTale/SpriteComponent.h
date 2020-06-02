#pragma once
#include "Components.h"
#include "TextureManager.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* texPath, int framesX, int framesY)
	{
		m_texture = TextureManager::Instance()->LoadTexture(texPath, TextureManager::Instance()->GetRenderer());

		SDL_QueryTexture(m_texture, NULL, NULL, &m_textureWidth, &m_textureHeight);

		m_framesX = framesX;
		m_framesY = framesY;
	}

	void Init() override
	{
		m_transformComponent = &entity->GetComponent<TransformComponent>();

		m_textureWidth = m_transformComponent->m_width;
		m_textureHeight = m_transformComponent->m_height;

		m_frameWidth = m_textureWidth;
		m_frameHeight = m_textureHeight;

		m_srcRect.w = m_frameWidth;
		m_srcRect.h = m_frameHeight;
		m_srcRect.x = 0;
		m_srcRect.y = 0;

		m_destRect.x = (int)m_transformComponent->m_position.x;
		m_destRect.y = (int)m_transformComponent->m_position.y;
		m_destRect.w = m_srcRect.w * m_transformComponent->m_scale;
		m_destRect.h = m_srcRect.h * m_transformComponent->m_scale;
	}

	void Update() override 
	{
		m_destRect.x = m_transformComponent->m_position.x;
		m_destRect.y = m_transformComponent->m_position.y;
	}

	void Draw() override 
	{
		TextureManager::Instance()->Draw(TextureManager::Instance()->GetRenderer(), m_texture, m_srcRect, m_destRect);
	}

	int GetFrameWidth()
	{
		return m_frameWidth;
	}

	int GetFrameHeight()
	{
		return m_frameHeight;
	}

	float GetRight()
	{
		return m_transformComponent->m_position.x + (m_destRect.w);
	}

	float GetBottom()
	{
		return m_transformComponent->m_position.y + (m_destRect.h);
	}

private:
	TransformComponent* m_transformComponent;
	SDL_Texture* m_texture;
	SDL_Rect m_srcRect, m_destRect;

	bool m_flipTexture = false;
	int m_frameWidth = 0;
	int m_frameHeight = 0;
	int m_textureWidth = 0;
	int m_textureHeight = 0;
	int m_framesX;
	int m_framesY;
};
