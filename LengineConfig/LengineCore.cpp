#include "LengineCore.h"
#include "Error.h"
#include <GL\glew.h>

//grabs the desktop res to auto the stand
LengineCore::LengineCore(){

	currentState = GameState::PLAY;

}


//inits everything and starts game loop

void LengineCore::run(){

	//init sub systems before looping
	initSubSystems();

	sprite.init(-50.0f, -50.0f, 100.0f, 100.0f);
	//model.init(-0.5, -0.5, 0.0, 1.0, 1.0);
	program.compile("Shaders/color.vert", "Shaders/color.frag");
	program.bindAttrib("vertexPosition", 0);
	program.bindAttrib("vertexColor", 1);
	program.bindAttrib("vertexUV", 2);
	
	camera.init(640, 480);
	program.linkShaders();
	while(currentState != GameState::EXIT){
	
		update();
		render();
		
	}



}

void LengineCore::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	program.use();

	 
	//camera.translate(1.1f, 1);
	glUniformMatrix4fv(program.getUniformLocation("cameraMatrix"), 1, GL_FALSE, camera.getUniformVal());
	sprite.render();
	//model.render();


	program.unuse();
	window.swapBuffer();
}

void LengineCore::update(){

	listener.update(currentState);

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





LengineCore::~LengineCore(){
}
