#pragma once
#include "world.h"
class GameLoop
{
public:

	GameLoop();
	~GameLoop();

	void Run(const float& delta);
	void render();
	bool Running();

private:

	bool m_running = false;
	void Init();
	void HandleEvents(const float& delta);

	//Screen position constants
	const int screenPosX = 50;
	const int screenPosY = 50;


	//Window title
	const char* screenTitle = "A Hybian tale";

	//SDL Window
	SDL_Window* m_window;
	World* world = nullptr;
};

