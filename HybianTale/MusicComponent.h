#pragma once
#include "Components.h"
#include "SoundManager.h"

class MusicComponent : Component
{
public:
	MusicComponent()
	{

	}

	void PlayMusic(const char* name)
	{
		Mix_PlayMusic(SoundManager::Instance()->GetMusic(name), -1);
	}

	void AddMusic(const char* name)
	{
		SoundManager::Instance()->LoadMusic(name);
	}
};