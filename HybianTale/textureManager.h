#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>

class TextureManager
{
public:
	
	SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* rend);
	void Draw(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	static TextureManager* Instance();
	SDL_Renderer* GetRenderer() { return m_renderer; }
	void SetRenderer(SDL_Renderer* ren) { m_renderer = ren; }
	~TextureManager();

private:

	//SDL renderer
	SDL_Renderer* m_renderer = nullptr;
	static TextureManager* mp_inst;
	TextureManager();
	int m_xpos = 0;
	int m_ypos = 0;
	static std::map<const char*, SDL_Texture*>* mp_textures;
};

