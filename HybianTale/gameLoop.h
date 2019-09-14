#pragma once
#include "world.h"
class gameLoop
{
public:

	gameLoop();
	~gameLoop();

	void run(float delta);
	void render();
	bool running();

private:

	bool m_running = false;
	void init();
	void handleEvents(float delta);
	SDL_Event event;

	//Screen position constants
	const int screenPosX = 50;
	const int screenPosY = 50;


	//Window title
	const char* screenTitle = "A Hybian tale";

	//SDL Window
	SDL_Window* m_window;
	world* World = nullptr;
};

