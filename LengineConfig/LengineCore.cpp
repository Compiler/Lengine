#include "LengineCore.h"
#include "Error.h"
#include <GL\glew.h>
#include "Light.h"

//grabs the desktop res to auto the stand
LengineCore::LengineCore(){

	currentState = GameState::PLAY;
	newTime = 0.0f;
	currentTime = 0.0f;
	deltaTime = 0.0f;
	count = 0;
	maxCap = 0.06f;
}


//inits everything and starts game loop

void LengineCore::run(){

	//init sub systems before looping
	initSubSystems();

	light.init(0.0f, 0.0f, 50.0f);

	while(currentState != GameState::EXIT){

		calculateDelta();

		update();
		render();
		
	}



}

void LengineCore::render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();
	

	 
	camera.translate(100.1f, 1);

	glUniform1i(program.getUniformLocation("samp"), 0);
	glUniformMatrix4fv(program.getUniformLocation("cameraMatrix"), 1, GL_FALSE, camera.getUniformVal());
	
	glUniform2fv(program.getUniformLocation("uResolution"), 1, (window.dimensions.vals));
	glUniform2fv(program.getUniformLocation("mouse"), 1, listener.position.vals);
	std::cout << "\n(" << listener.position.x << ", " << listener.position.y / window.dimensions.vals[1] << ")";


	light.set(program.getUniformLocation("light0"));

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


	sprite.init("Textures/brick.png", -320.0f, -240.0f, 640.0f, 480.0f);
	//model.init(-0.5, -0.5, 0.0, 1.0, 1.0);
	program.compile("Shaders/color.vert", "Shaders/light.frag");
	program.bindAttrib("vertexPosition", 0);
	program.bindAttrib("vertexColor", 1);
	program.bindAttrib("vertexUV", 2);
	
	
	camera.init(640, 480);
	program.linkShaders();
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


void LengineCore::calculateDelta() {
	newTime = SDL_GetTicks();
	deltaTime = 0;
	averages[count % 10] = newTime - currentTime;;

	currentTime = newTime;
	for (int i = 0; i < 10; i++)
		deltaTime += averages[i];
	deltaTime = deltaTime / 10 / 1000;

	if (deltaTime < maxCap)
		SDL_Delay(100);
}


LengineCore::~LengineCore(){
}
