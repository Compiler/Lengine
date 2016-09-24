#pragma once

#include <SDL\SDL.h>


class LengineCore{
public:
	LengineCore();


	void run();
	~LengineCore();

private:

	void initSubSystems();
	void render();
	void update();

	SDL_Window* window;
	SDL_Event event;

};

