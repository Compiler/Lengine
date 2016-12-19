#pragma once

#include <SDL\SDL.h>

#include <string>
class Window
{
public:
	Window();

	void create(std::string name, int width, int height);
	void setTitle(std::string name);
	void changeSize(int width, int height);

	void swapBuffer();

	~Window();

private:

	SDL_Window* window;
	

};

