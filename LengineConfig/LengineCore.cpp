#include "LengineCore.h"
#include "ScreenHelper.h"
#include "Error.h"


//grabs the desktop res to auto the stand
LengineCore::LengineCore(){
	
	ScreenHelper::GetDesktopResolution(width, height);
	std::cout << "Width: " << width << ", Height: " << height << std::endl;
	

}


//inits everything and starts game loop

void LengineCore::run(){

	//init sub systems before looping
	initSubSystems();

	while(true){
	
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

	window.create();

}


void LengineCore::render(){




}

void LengineCore::update(){




}



LengineCore::~LengineCore(){
}
