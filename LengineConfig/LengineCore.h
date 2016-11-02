#pragma once

#include <SDL\SDL.h>
#include "Window.h"
#include "InputListener.h"
#include "GameState.h"
#include "Sprite.h"

class LengineCore{

public:
	LengineCore();



	



	void run();
	void setHeight();
	void setWidth();
	void setFlag();
	~LengineCore();

private:

	void initSubSystems();
	void render();
	void update();
	
	void subSDLInit();
	void subWindow();


	unsigned int width, height;
	Window window;
	InputListener listener;
	GameState currentState;
	
	Sprite sprite;

};

