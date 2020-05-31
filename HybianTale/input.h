#pragma once
#include "command.h"


enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_ESC, KEY_NUM_OF
};

class Input
{

public:
	Input();
	~Input();

	Command* UpdateInput(SDL_Event ev);

private:

	bool m_keysPressed[KEY_NUM_OF];

	Command* m_leftMove;
	Command* m_rightMove;
	Command* m_downMove;
	Command* m_upMove;

};