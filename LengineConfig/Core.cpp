#include "Core.h"



Core::Core(): currentState(GameState::PLAY)
{

	

}


void inline Core::init() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Error::throwAndClose("SDL could not initialize");
	}

	width = 640;
	height = 480;
	window.create("Engine", width, height);


	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		Error::throwAndClose("Glew could NOT initialize");
	}
	



}

void Core::run() {

	init();


	while (currentState != GameState::EXIT) {

		update();

		render();

	}


}


void Core::render() {
	glViewport(0, 0, width, height);
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

	listener.update(currentState);


}



Core::~Core()
{

	SDL_Quit();

}
