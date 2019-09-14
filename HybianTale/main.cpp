#define SDL_MAIN_HANDLED
#include "gameLoop.h"

Uint64 now = SDL_GetPerformanceCounter();
Uint64 last = 0;
float deltaTime = 0.0;
gameLoop* game = new gameLoop();

int main()
{
	while (game->running())
	{
		last = now;
		now = SDL_GetPerformanceCounter();
		deltaTime = ((now - last) * FPS / (float)SDL_GetPerformanceFrequency());

		game->run(deltaTime);
		game->render();
	}

	delete game;
	game = nullptr;

	return 0;
}