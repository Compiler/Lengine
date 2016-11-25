
#include <iostream>
#include <SDL\SDL.h>
#include "LengineCore.h"
#include <lml\Mat2.h>
#include <GL\glew.h>
//start of app
int main(int argc, char** argv){

	lml::Mat2 mat(1.0,2.0,3.0,4.0);
	std::cout << "\n\nCurrent matrix:\n[" << mat.elementAt(0, 0) << "  " << mat.elementAt(1, 0) << "]\n[" << mat.elementAt(0, 1) << "  " << mat.elementAt(1, 1);
	mat.transpose();
	std::cout << "\n\Transpose matrix:\n[" << mat.elementAt(0, 0) << "  " << mat.elementAt(1, 0) << "]\n[" << mat.elementAt(0, 1) << "  " << mat.elementAt(1, 1);
	mat.transpose();
	std::cout << "\n\Transpose back:\n[" << mat.elementAt(0, 0) << "  " << mat.elementAt(1, 0) << "]\n[" << mat.elementAt(0, 1) << "  " << mat.elementAt(1, 1);
	SDL_Delay(500000);
	//run the main loop
	LengineCore core;
	core.run();

	return 0;
}
