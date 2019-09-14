#pragma once
#include "command.h"


enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_ESC, KEY_NUM_OF
};

class input
{

public:
	input();
	~input();

	command* updateInput(SDL_Event ev);

private:

	bool m_keysPressed[KEY_NUM_OF];

	command* leftMove;
	command* rightMove;
	command* downMove;
	command* upMove;

};