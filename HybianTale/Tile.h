#pragma once
#include "Components.h"
#include "textureManager.h"

//Class that is lighter than Entity. For if we want to create something that renders but never moves.
class Tile
{
public:
	Tile(const char* filename, int xPos, int yPos, int srcX, int srcY, int width, int height, float scale, SDL_Renderer* rend)
	{

		m_src.w = width;
		m_src.h = height;
		m_src.x = srcX;
		m_src.y = srcY;

		m_dest.x = xPos;
		m_dest.y = yPos;
		m_dest.w = m_src.w * scale;
		m_dest.h = m_src.h * scale;

		m_texture = TextureManager::Instance()->LoadTexture(filename);

		SDL_QueryTexture(m_texture, NULL, NULL, &width, &height);
	}

	~Tile()
	{
		if (m_texture)
		{
			delete m_texture;
			m_texture = nullptr;
		}
	}

	void Draw()
	{
		TextureManager::Instance()->Draw(m_texture, m_src, m_dest, false);
	}

	void SetPosition(int x, int y)
	{
		m_dest.x = x;
		m_dest.y = y;
	}

	void SetX(int x)
	{
		m_dest.x = x;
	}

	void SetY(int y)
	{
		m_dest.y = y;
	}

	int GetX()
	{
		return m_dest.x;
	}

	int GetY()
	{
		return m_dest.y;
	}

private:

	SDL_Texture* m_texture;
	SDL_Rect m_src, m_dest;
};
