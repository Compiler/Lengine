#include "Window.h"
#include "Error.h"


Window::Window()
{
}


void Window::create(std::string name, GLint width, GLint height) {
	this->width = width;
	this->height = height;
	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		Error::throwAndClose("Couldn't initialize SDL_Window");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//Stores context in window, therefor delete context object
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if (glContext == nullptr)
		Error::throwAndClose("Couldnt initialize Context");


	SDL_GL_SetSwapInterval(1);
}

void Window::setTitle(std::string name) {
	SDL_SetWindowTitle(window, name.c_str());
}

void Window::changeSize(GLint width, GLint height) {
	this->width = width;
	this->height = height;
	SDL_SetWindowSize(window, width, height);
}

void Window::swapBuffer() {
	SDL_GL_SwapWindow(window);
}

GLint Window::getWidth() {
	SDL_GetWindowSize(window, &width, &height);
	return width;

}
GLint Window::getHeight() {
	SDL_GetWindowSize(window, &width, &height);
	return height;
}

GLfloat Window::getRatio() {
	SDL_GetWindowSize(window, &width, &height);
	return (GLfloat)width / height;
}

Window::~Window()
{

	SDL_DestroyWindow(window);

}
