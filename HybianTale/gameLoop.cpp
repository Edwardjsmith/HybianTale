#include "gameLoop.h"



GameLoop::GameLoop()
{
	Init();
}


GameLoop::~GameLoop()
{
}


void GameLoop::Run(const float& delta)
{
	HandleEvents(delta);
}

bool GameLoop::Running()
{
	return m_running;
}

void GameLoop::Init()
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

	TextureManager::Instance()->SetRenderer(SDL_CreateRenderer(m_window, -1, 0));

	if (!TextureManager::Instance()->GetRenderer())
	{
		std::cout << "Renderer init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue\n" << std::endl;
		getchar();
		return;
	}

	world = new World();

	m_running = true;
}

void GameLoop::HandleEvents(const float& delta)
{
	SDL_RenderClear(TextureManager::Instance()->GetRenderer()); //Wipes display to desired colour
	world->Update(delta);
	SDL_RenderPresent(TextureManager::Instance()->GetRenderer()); //Presents colour
}

void GameLoop::render()
{

}
