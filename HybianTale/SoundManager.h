#pragma once
#include <SDL_mixer.h>
#include <map>
class SoundManager
{
public:
	
	~SoundManager();

	static SoundManager* Instance();

	Mix_Music* LoadMusic(const char* name);
	Mix_Chunk* LoadSound(const char* name);

	Mix_Music* GetMusic(const char* name)
	{
		return m_music.at(name);
	}
	Mix_Chunk* GetSound(const char* name)
	{
		return m_sound.at(name);
	}

private:
	SoundManager();
	static SoundManager* p_instance;

	std::map<const char*, Mix_Music*> m_music;
	std::map<const char*, Mix_Chunk*> m_sound;
};

