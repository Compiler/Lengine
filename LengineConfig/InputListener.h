#pragma once

#include <SDL/SDL.h>
#include "GameState.h"

class InputListener
{
public:
	InputListener();

	void update(GameState &state);

	~InputListener();

private:
	SDL_Event event;
};

