#pragma once
#include "Components.h"
#include "TextureManager.h"


struct Animation
{
public:

	Animation(int index, int frames, int speed)
	{
		m_index = index;
		m_frames = frames;
		m_speed = speed;
	}

	int m_index;
	int m_frames;
	float m_speed;
};

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* texPath, bool animated)
	{
		m_texture = TextureManager::Instance()->LoadTexture(texPath, TextureManager::Instance()->GetRenderer());

		SDL_QueryTexture(m_texture, NULL, NULL, &m_textureWidth, &m_textureHeight);

		m_animated = animated;
	}

	~SpriteComponent()
	{
		for (std::map<const char*, Animation*>::iterator itr = m_animations.begin(); itr != m_animations.end(); ++itr)
		{
			delete itr->first;
			delete itr->second;
		}
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
		if (m_animated)
		{
			m_srcRect.x = m_frameWidth * ((int)(SDL_GetTicks() / m_speed) % m_frames);
		}

		m_srcRect.y = m_textureHeight * m_frameIndex;

		m_destRect.x = m_transformComponent->m_position.x;
		m_destRect.y = m_transformComponent->m_position.y;
	}

	void Draw() override 
	{
		TextureManager::Instance()->Draw(TextureManager::Instance()->GetRenderer(), m_texture, m_srcRect, m_destRect, m_flipSprite);
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

	void PlayAnimation(const char* name)
	{
		m_frames = m_animations[name]->m_frames;
		m_frameIndex = m_animations[name]->m_index;
		m_speed = m_animations[name]->m_speed;
	}

	void AddAnimation(const char* name, int frameIndex, int frames, float speed)
	{
		Animation* anim = new Animation(frameIndex, frames, speed);
		m_animations.emplace(name, anim);
	}

	void FlipSprite(bool flip)
	{
		m_flipSprite = flip;
	}
	

private:
	TransformComponent* m_transformComponent;
	SDL_Texture* m_texture;
	SDL_Rect m_srcRect, m_destRect;

	bool m_flipSprite = false;
	bool m_animated = false;

	float m_speed = 0.0f;
	int m_frameWidth = 0;
	int m_frameHeight = 0;
	int m_textureWidth = 0;
	int m_textureHeight = 0;
	int m_frames = 1;
	int m_frameIndex = 1;
	std::map<const char*, Animation*> m_animations;
};
