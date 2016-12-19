#include "Core.h"



Core::Core()
{
}


void Core::init() {
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		Error::throwAndClose("Glew could NOT initialize");
	}
	


}

void Core::run() {

	init();


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLineWidth(3);               //<-- Thicken lines so we can see 'em clearly

	while (true) {

		update();

		render();

	}


}


void Core::render() {
	glClearColor(.2, .2, .2, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


}

void Core::update() {



}



Core::~Core()
{
}
