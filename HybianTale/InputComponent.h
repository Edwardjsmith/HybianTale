#pragma once
#include "Components.h"
#include <SDL.h>

class Command;

enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_ESC, KEY_NUM_OF
};

class InputComponent : public Component
{

public:
	InputComponent();
	~InputComponent();

	Command* UpdateInput(SDL_Event ev);

	void Update(const float& delta) override;
	void Init() override;

	bool disableInput = false;

private:

	bool m_keysPressed[KEY_NUM_OF];

	Command* m_leftMove;
	Command* m_rightMove;
	Command* m_downMove;
	Command* m_upMove;

	SDL_Event m_event;
	TransformComponent* m_transformComponent;
	Command* m_command;
};