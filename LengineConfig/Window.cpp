#include "Window.h"



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

	screenWidth = screenWidth;
	screenHeight = screenHeight;

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);

	if(window == nullptr){}
		//Lengine::Error::throwException("Window initialization failed", -1, true);


	//Stores context in window, therefor delete context object asap ferg
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if(glContext == nullptr){}
		//Lengine::Error::throwException("Couldnt initialize Context", -1, true);

	if(glewInit() != GLEW_OK){
		//Lengine::Error::throwException("Couldnt initialize GLEW", -1, true);
	}



	//sets to context for glClearBufferBit
	glClearColor(0.0f, 0.0f, 0.0f, 1);
	//SDL_GL_DeleteContext(glContext);




	SDL_GL_SetSwapInterval(1);
	std::printf("***   OpenG Version: %s ***", glGetString(GL_VERSION));

	return 1;
}
	


}

void Window::setName(std::string newName){



}

void Window::displayFPS(Uint32 frames){



}

void Window::swapBuffer(){



}




Window::~Window(){
}
