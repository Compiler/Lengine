#include "LengineCore.h"
#include "ScreenHelper.h"
#include "Error.h"


//grabs the desktop res to auto the stand
LengineCore::LengineCore(){
	
	ScreenHelper::GetDesktopResolution(width, height);
	std::cout << "Width: " << width << ", Height: " << height << std::endl;
	

	currentState = GameState::PLAY;

}


//inits everything and starts game loop

void LengineCore::run(){

	//init sub systems before looping
	initSubSystems();

	while(currentState != GameState::EXIT){
	
		update();
		render();
		
	}



}



//wrapper for calling class
void LengineCore::initSubSystems(){
	subSDLInit();
	subWindow();
}

//inits sdl2 and sets the double buffer
void LengineCore::subSDLInit(){

	int code = SDL_Init(SDL_INIT_EVERYTHING);

	if(code == -1){
		Error::throwException(Error::ExceptionType::GENERAL, "Couldn't init SDL2", true);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


}


//creates the window
void LengineCore::subWindow(){

	if(window.create() != 1){
		Error::throwException(Error::ExceptionType::GENERAL, "Couldn't create the window", true);
	}

}


void LengineCore::render(){
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	window.swapBuffer();
}

void LengineCore::update(){

	listener.update(currentState);

}



LengineCore::~LengineCore(){
}