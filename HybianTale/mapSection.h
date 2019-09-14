#pragma once
#include "spacialPartition.h"
#include "player.h"
#include "objectPool.h"
#include <map>
#include <fstream>
#include <string>

class mapSection 
{
public:
	mapSection();
	~mapSection();

	void loadSection(std::string filename, SDL_Renderer * ren);
	void updateSection(float delta, SDL_Renderer * ren);
	void addEntity(entity* ent);
	void leaveSection();
	void enterSection();

	void addEnemyPos(const char* tag, Vector2 pos);

	spacialPartition* partition;
private:

	std::map<const char*, Vector2> terrain;
	std::map<const char*, Vector2> enemyPos;

	const int sizeY = SCREEN_HEIGHT / 16;
	const int sizeX = SCREEN_WIDTH / 16;
};

