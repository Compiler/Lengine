#include "Window.h"
#include "Error.h"


Window::Window()
{
}


void Window::create(std::string name, int width, int height) {

	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	
	if (window == nullptr) {
		Error::throwAndClose("Couldn't initialize SDL_Window");
	}
}

void Window::setTitle(std::string name) {

}

void Window::changeSize(int width, int height) {
		
}

void Window::swapBuffer() {
	
}


Window::~Window()
{
}
