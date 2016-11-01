#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <string>

//flags consist of the allowed properties supported by Lengine
enum WindowFlags{
	HIDDEN = 0x1,
	SHOWN = 0x2,
	BORDERLESS = 0x4,
	FULL_SCREEN = 0x8
};

class Window{
public:
	Window();


	int create(std::string title = "My Game", int xPos = 0, int yPos = 0, unsigned int width = 640, unsigned int height = 480, unsigned int currentFlags = WindowFlags::SHOWN | SDL_WINDOW_OPENGL);

	void setName(std::string newName);
	void displayFPS(Uint32 frames);
	void swapBuffer();

	int getWidth(){ return screenWidth; }
	int getHeight(){ return screenHeight; }

	~Window();


private:

	SDL_Window* window;
	int screenWidth, screenHeight;

};

