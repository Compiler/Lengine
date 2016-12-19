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
	SDL_SetWindowTitle(window, name.c_str());
}

void Window::changeSize(int width, int height) {
	SDL_SetWindowSize(window, width, height);
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(window);
}


Window::~Window()
{
}
