#pragma once
#include <GL\glew.h>
#include <SDL\SDL.h>
#include "Error.h"

class Core
{
public:
	Core();

	void run();

	~Core();
private:

	void init();
	void render();
	void update();
};

