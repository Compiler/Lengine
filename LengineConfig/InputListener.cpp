#include "InputListener.h"



InputListener::InputListener()
{
}

void InputListener::update(GameState &state) {
	while (SDL_PollEvent(&event)) {
	
		switch (event.type) {
		
			case SDL_QUIT: {
				state = GameState::EXIT;
			}

		}

	}
}

InputListener::~InputListener()
{
}
