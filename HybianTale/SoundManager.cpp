#include "SoundManager.h"
SoundManager* SoundManager::p_instance = nullptr;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	if (p_instance)
	{
		delete p_instance;
		p_instance = nullptr;
	}

	for (std::map<const char*, Mix_Music*>::iterator itr = m_music.begin(); itr != m_music.end(); ++itr)
	{
		delete itr->first;
		delete itr->second;
	}

	for (std::map<const char*, Mix_Chunk*>::iterator itr = m_sound.begin(); itr != m_sound.end(); ++itr)
	{
		delete itr->first;
		delete itr->second;
	}
}

SoundManager* SoundManager::Instance()
{
	if (p_instance == nullptr)
	{
		p_instance = new SoundManager();
	}

	return p_instance;
}

Mix_Music* SoundManager::LoadMusic(const char* name)
{
	if (!m_music.count(name))
	{
		m_music.insert(std::pair<const char*, Mix_Music*>(name, Mix_LoadMUS(name)));
	}

	return m_music.at(name);
}

Mix_Chunk* SoundManager::LoadSound(const char* name)
{
	if (!m_sound.count(name))
	{
		m_sound.insert(std::pair<const char*, Mix_Chunk*>(name, Mix_LoadWAV(name)));
	}

	return m_sound.at(name);
}
