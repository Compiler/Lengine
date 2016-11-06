
#include <iostream>
#include <SDL\SDL.h>
#include "LengineCore.h"
#include "mat4.h"
#include <GL\glew.h>
//start of app
int main(int argc, char** argv){
	GLfloat ay[16] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	
	mat4 mat(ay);

	//run the main loop
	LengineCore core;
	core.run();

	return 0;
}
