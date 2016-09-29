#include "LengineCore.h"
#include "ScreenHelper.h"


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
		exit(-1);
	}


}
void LengineCore::subWindow(){

	window = SDL_CreateWindow("Lengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width / 2, height / 2, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if(window == nullptr){
		exit(-1);
	}

}


void LengineCore::render(){




}

void LengineCore::update(){




}



LengineCore::~LengineCore(){
}
