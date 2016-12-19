#pragma once
#include <GL\glew.h>
#include <SDL\SDL.h>
#include "Error.h"
#include "Window.h"

class Core
{
public:
	Core();

	void run();

	~Core();
private:

	void inline init();
	void render();
	void update();

	Window window;
	

};

