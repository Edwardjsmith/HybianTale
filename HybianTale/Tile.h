#pragma once
#include "Components.h"
#include "textureManager.h"

//Class that is lighter than Entity. For if we want to create something that renders but never moves.
class Tile
{
public:
	Tile(const char* filename, float x, float y, int width, int height, float scale, SDL_Renderer* rend)
	{

		m_src.w = width;
		m_src.h = height;
		m_src.x = 0;
		m_src.y = 0;

		m_dest.x = static_cast<int>(x);
		m_dest.y = static_cast<int>(y);
		m_dest.w = m_src.w * scale;
		m_dest.h = m_src.h * scale;

		m_texture = TextureManager::Instance()->LoadTexture(filename);

		SDL_QueryTexture(m_texture, NULL, NULL, &width, &height);
	}

	void Draw()
	{
		TextureManager::Instance()->Draw(m_texture, m_src, m_dest, false);
	}

	~Tile()
	{
		if (m_texture)
		{
			delete m_texture;
			m_texture = nullptr;
		}
	}

private:

	SDL_Texture* m_texture;
	SDL_Rect m_src, m_dest;
};
