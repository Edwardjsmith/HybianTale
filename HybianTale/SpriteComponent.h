#pragma once
#include "Components.h"
#include "TextureManager.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(const char* texPath)
	{
		m_texture = TextureManager::Instance()->LoadTexture(texPath, TextureManager::Instance()->GetRenderer());
	}

	void Init() override
	{
		m_position = &entity->GetComponent<PositionComponent>();

		m_srcRect.x = m_srcRect.y = 0;
		m_srcRect.w = m_srcRect.h = 32;

		m_destRect.w = m_destRect.h = 64;

	}

	void Update() override 
	{
		m_destRect.x = m_position->GetX();
		m_destRect.y = m_position->GetY();
	}

	void Draw() override 
	{
		TextureManager::Instance()->Draw(TextureManager::Instance()->GetRenderer(), m_texture, m_srcRect, m_destRect);
	}
private:
	PositionComponent* m_position;
	SDL_Texture* m_texture;
	SDL_Rect m_srcRect, m_destRect;
};
