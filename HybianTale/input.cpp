#include "input.h"

input::input()
{
	leftMove = new LeftCommand();
	rightMove = new RightCommand();
	upMove = new UpCommand();
	downMove = new DownCommand();

	m_keysPressed[KEY_DOWN] = false;
	m_keysPressed[KEY_LEFT] = false;
	m_keysPressed[KEY_RIGHT] = false;
	m_keysPressed[KEY_UP] = false;
	m_keysPressed[KEY_ESCAPE] = false;
}

input::~input()
{
	if (upMove)
	{
		delete upMove;
		upMove = nullptr;
	}
	if (downMove)
	{
		delete downMove;
		downMove = nullptr;
	}
	if (leftMove)
	{
		delete leftMove;
		leftMove = nullptr;
	}
	if (rightMove)
	{
		delete rightMove;
		rightMove = nullptr;
	}
	if (downMove)
	{
		delete downMove;
		downMove = nullptr;
	}
}


command* input::updateInput(SDL_Event ev)
{

	if (ev.type == SDL_KEYDOWN)
	{
		SDL_Keycode keyPressed = ev.key.keysym.sym;

		switch (keyPressed)
		{

		case SDLK_DOWN:
			m_keysPressed[KEY_DOWN] = true;
			break;


		case SDLK_LEFT:

			m_keysPressed[KEY_LEFT] = true;
			break;


		case SDLK_RIGHT:

			m_keysPressed[KEY_RIGHT] = true;
			break;

		case SDLK_UP:
			m_keysPressed[KEY_UP] = true;
			break;

		case SDLK_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = true;
			break;

		default: break;
		}


	}

	else if (ev.type == SDL_KEYUP)
	{
		SDL_Keycode keyPressed = ev.key.keysym.sym;

		switch (keyPressed)
		{
		case SDLK_DOWN:
			m_keysPressed[KEY_DOWN] = false;
			break;

		case SDLK_LEFT:
			m_keysPressed[KEY_LEFT] = false;
			break;
		case SDLK_RIGHT:
			m_keysPressed[KEY_RIGHT] = false;
			break;

		case SDLK_UP:
			m_keysPressed[KEY_UP] = false;
			break;

		case SDLK_ESCAPE:
			m_keysPressed[KEY_ESCAPE] = false;
			break;

		default: break;
		}

	}

	if (m_keysPressed[KEY_DOWN])
	{
		return downMove;
	}
	if (m_keysPressed[KEY_LEFT])
	{
		return leftMove;
	}
	if (m_keysPressed[KEY_RIGHT])
	{

		return rightMove;
	}
	if (m_keysPressed[KEY_UP])
	{
		return upMove;
	}


	return NULL;



}