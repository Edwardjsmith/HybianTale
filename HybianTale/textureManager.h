#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <map>

class textureManager
{
public:
	
	SDL_Texture* load(const char* filename, SDL_Renderer* rend);
	void draw(SDL_Renderer* rend, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	static textureManager* instance();
	SDL_Renderer* getRenderer() { return m_renderer; }
	void setRenderer(SDL_Renderer* ren) { m_renderer = ren; }
	~textureManager();

private:

	//SDL renderer
	SDL_Renderer* m_renderer;
	static textureManager* inst;
	textureManager();
	int m_xpos, m_ypos;
	static std::map<const char*, SDL_Texture*>* m_textures;
};

