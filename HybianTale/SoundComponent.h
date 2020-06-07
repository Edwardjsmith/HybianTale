#pragma once
#include "Components.h"
#include "SoundManager.h"

class SoundComponent : Component
{
public:
	SoundComponent()
	{

	}

	void PlaySound(const char* name)
	{
		Mix_PlayChannel(-1, SoundManager::Instance()->GetSound(name), 0);
	}

	void AddSound(const char* name)
	{
		SoundManager::Instance()->LoadSound(name);
	}
};
