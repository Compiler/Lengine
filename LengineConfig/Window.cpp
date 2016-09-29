#include "Window.h"
#include <SDL\SDL.h>
#include <GL\gl.h>
#include "Error.h"


Window::Window(): screenWidth(640), screenHeight(480){
}


int Window::create(std::string title, int xPos, int yPos, unsigned int width, unsigned int height, unsigned int currentFlags){
	

	Uint32 flags = SDL_WINDOW_OPENGL;

	if(currentFlags & WindowFlags::HIDDEN)
		flags |= SDL_WINDOW_HIDDEN;

	if(currentFlags & WindowFlags::BORDERLESS)
		flags |= SDL_WINDOW_BORDERLESS;

	if(currentFlags & WindowFlags::FULL_SCREEN)
		flags |= SDL_WINDOW_FULLSCREEN;

	screenWidth = width;
	screenHeight = height;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

	if(window == nullptr){}
	Error::throwException(Error::ExceptionType::INIT, "Window initialization failed", true);


	//Stores context in window, therefor delete context object asap ferg
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if(glContext == nullptr){}
		Error::throwException(Error::ExceptionType::INIT, "Couldnt initialize Context", true);

	if(glewInit() != GLEW_OK){
		Error::throwException(Error::ExceptionType::INIT, "Couldnt initialize GLEW", true);
	}



	//sets to context for glClearBufferBit
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	//SDL_GL_DeleteContext(glContext);




	SDL_GL_SetSwapInterval(1);
	std::printf("***   OpenG Version: %s ***", glGetString(GL_VERSION));

	return 1;
}
	

void Window::setName(std::string newName){



}

void Window::displayFPS(Uint32 frames){



}

void Window::swapBuffer(){



}




Window::~Window(){
}
