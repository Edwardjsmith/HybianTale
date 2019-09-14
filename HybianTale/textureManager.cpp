#include "textureManager.h"

textureManager* textureManager::inst = nullptr;
std::map<const char*, SDL_Texture*>* textureManager::m_textures = nullptr;

textureManager::textureManager()
{
	m_textures = new std::map<const char*, SDL_Texture*>();
}


SDL_Texture* textureManager::load(const char * filename, SDL_Renderer* rend)
{
	if (!m_textures->count(filename))
	{
		SDL_Surface* surface = IMG_Load(filename);

		if (surface == nullptr)
		{
			printf("IMG_Load: %s\n", IMG_GetError());
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
		m_textures->insert(std::pair<const char*, SDL_Texture*>(filename, tex));
		SDL_FreeSurface(surface);
	}

	return m_textures->at(filename);
}

void textureManager::draw(SDL_Renderer* rend, SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(rend, tex, &src, &dest);
}

textureManager* textureManager::instance()
{
	if (inst == nullptr)
	{
		inst = new textureManager();
	}
	return inst;
}

textureManager::~textureManager()
{
	for (std::map<const char*, SDL_Texture*>::iterator itr = m_textures->begin(); itr != m_textures->end(); itr++)
	{
		delete itr->first;
		delete itr->second;
	}

	delete m_textures;
	m_textures = nullptr;

	if (inst)
	{
		delete inst;
		inst = nullptr;
	}
}
