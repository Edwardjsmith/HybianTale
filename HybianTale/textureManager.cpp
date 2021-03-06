#include "textureManager.h"

TextureManager* TextureManager::mp_inst = nullptr;
std::map<const char*, SDL_Texture*>* TextureManager::mp_textures = nullptr;

TextureManager::TextureManager()
{
	mp_textures = new std::map<const char*, SDL_Texture*>();
}


SDL_Texture* TextureManager::LoadTexture(const char * filename)
{
	if (!mp_textures->count(filename))
	{
		SDL_Surface* surface = IMG_Load(filename);

		if (surface == nullptr)
		{
			printf("IMG_Load: %s\n", IMG_GetError());
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, surface);
		mp_textures->insert(std::pair<const char*, SDL_Texture*>(filename, tex));
		SDL_FreeSurface(surface);
	}

	return mp_textures->at(filename);
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest, bool flip)
{
	SDL_RendererFlip sdlFlip = flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
	SDL_RenderCopyEx(m_renderer, tex, &src, &dest, 0, 0, sdlFlip);
}

TextureManager* TextureManager::Instance()
{
	if (mp_inst == nullptr)
	{
		mp_inst = new TextureManager();
	}
	return mp_inst;
}

TextureManager::~TextureManager()
{
	for (std::map<const char*, SDL_Texture*>::iterator itr = mp_textures->begin(); itr != mp_textures->end(); ++itr)
	{
		delete itr->first;
		delete itr->second;
	}

	delete mp_textures;
	mp_textures = nullptr;

	if (mp_inst)
	{
		delete mp_inst;
		mp_inst = nullptr;
	}
}
