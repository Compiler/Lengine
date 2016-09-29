#include "LengineCore.h"
#include "ScreenHelper.h"
#include "Error.h"

LengineCore::LengineCore(){
	
	ScreenHelper::GetDesktopResolution(width, height);
	std::cout << "Width: " << width << ", Height: " << height << std::endl;
	

}



void LengineCore::run(){

	//init sub systems before looping
	initSubSystems();

	while(true){
	
		update();
		render();
		
	}



}


void LengineCore::initSubSystems(){
	subSDLInit();
	subWindow();

}


void LengineCore::subSDLInit(){

	int code = SDL_Init(SDL_INIT_EVERYTHING);

	if(code == -1){
		Error::throwException(Error::ExceptionType::GENERAL, "Couldn't init SDL2", true);
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


}
void LengineCore::subWindow(){

	window.create();

}


void LengineCore::render(){




}

void LengineCore::update(){




}



LengineCore::~LengineCore(){
}
