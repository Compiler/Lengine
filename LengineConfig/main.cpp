
#include <iostream>

#include <GL\glew.h>
#include <SDL\SDL.h>



//start of app
int main(int argc, char** argv){
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Error initializing SDL";
	}



	

	return 0;
}
