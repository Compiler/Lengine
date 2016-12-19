#include "Core.h"



Core::Core()
{
}


void inline Core::init() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Error::throwAndClose("SDL could not initialize");
	}


	window.create("Engine", 640, 480);


	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		Error::throwAndClose("Glew could NOT initialize");
	}
	



}

void Core::run() {

	init();


	while (true) {

		update();

		render();

	}


}


void Core::render() {
	glViewport(0, 0, window.getWidth(), window.getHeight());
	glClearColor(.2, .2, .2, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -0.5f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.5f);
	glEnd();
	window.swapBuffer();
}

void Core::update() {



}



Core::~Core()
{

	SDL_Quit();

}
