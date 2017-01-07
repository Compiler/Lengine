
#include <iostream>

#include <GL\glew.h>
#include <SDL\SDL.h>



//start of app
int main(int argc, char** argv){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) std::cout << "Error initializing SDL\n";

	SDL_Window *window;
	window = SDL_CreateWindow("Temporary", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);
	if(glewInit() != GLEW_OK) std::cout << "Error initializing GLEW\n";
	
	system("PAUSE");
	return 0;
}
