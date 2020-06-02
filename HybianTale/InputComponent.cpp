#include "InputComponent.h"
#include "command.h"


InputComponent::InputComponent()
{

}

InputComponent::~InputComponent()
{
	if (m_upMove)
	{
		delete m_upMove;
		m_upMove = nullptr;
	}
	if (m_downMove)
	{
		delete m_downMove;
		m_downMove = nullptr;
	}
	if (m_leftMove)
	{
		delete m_leftMove;
		m_leftMove = nullptr;
	}
	if (m_rightMove)
	{
		delete m_rightMove;
		m_rightMove = nullptr;
	}
	if (m_downMove)
	{
		delete m_downMove;
		m_downMove = nullptr;
	}
}


Command* InputComponent::UpdateInput(SDL_Event ev)
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
		m_transformComponent->m_velocity = { 0,0 };
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
		return m_downMove;
	}
	if (m_keysPressed[KEY_LEFT])
	{
		return m_leftMove;
	}
	if (m_keysPressed[KEY_RIGHT])
	{

		return m_rightMove;
	}
	if (m_keysPressed[KEY_UP])
	{
		return m_upMove;
	}


	return NULL;



}

void InputComponent::Update(const float& delta)
{
	SDL_PollEvent(&m_event);
	m_command = UpdateInput(m_event);

	if (m_command)
	{
		m_command->Execute(m_transformComponent);
	}
}

void InputComponent::Init()
{
	m_transformComponent = &entity->GetComponent<TransformComponent>();

	m_leftMove = new LeftCommand();
	m_rightMove = new RightCommand();
	m_upMove = new UpCommand();
	m_downMove = new DownCommand();

	m_keysPressed[KEY_DOWN] = false;
	m_keysPressed[KEY_LEFT] = false;
	m_keysPressed[KEY_RIGHT] = false;
	m_keysPressed[KEY_UP] = false;
	m_keysPressed[KEY_ESCAPE] = false;
}
