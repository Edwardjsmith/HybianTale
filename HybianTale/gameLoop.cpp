#include "gameLoop.h"



gameLoop::gameLoop()
{
	init();
}


gameLoop::~gameLoop()
{
}


void gameLoop::run(float delta)
{
	handleEvents(delta);
}

bool gameLoop::running()
{
	return m_running;
}

void gameLoop::init()
{
	m_window = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);			
	m_window = SDL_CreateWindow(screenTitle, screenPosX, screenPosY, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (!m_window)
	{
		std::cout << "Window init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue" << std::endl;
		getchar();
		return;
	}

	textureManager::instance()->setRenderer(SDL_CreateRenderer(m_window, -1, 0));

	if (!textureManager::instance()->getRenderer())
	{
		std::cout << "Renderer init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue\n" << std::endl;
		getchar();
		return;
	}

	World = new world(textureManager::instance()->getRenderer());

	m_running = true;
}

void gameLoop::handleEvents(float delta)
{
	SDL_PollEvent(&event);
	SDL_RenderClear(textureManager::instance()->getRenderer()); //Wipes display to desired colour
	World->update(textureManager::instance()->getRenderer(), delta, event);
	SDL_RenderPresent(textureManager::instance()->getRenderer()); //Presents colour
}

void gameLoop::render()
{

}
