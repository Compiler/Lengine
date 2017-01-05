#include "Core.h"

#include "Vertex.h"

#include "glm/gtc/matrix_transform.hpp"  
#include "glm/gtc/type_ptr.hpp" 
#include <glm\glm.hpp>



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
	if (GLenum error = glewInit() != GLEW_OK) {
		printf("GLEW initialization threw an error: %s\n", glewGetErrorString(error));
		Error::throwAndClose("");
	}
	

	checkSupport();


	cam.init(width, height);

}

void Core::checkSupport() {
	
	if (!GLEW_VERSION_4_5) {
		printf("OpenGL Version 4.5 not supported!\n");
		if (!GLEW_VERSION_3_1) {
			printf("OpenGL Version 3.1 not supported!\n");
			if (!GLEW_VERSION_1_3) {
				printf("OpenGL Version 2.1 not supported!\n");
				currentState = GameState::EXIT;
			}else  printf("OpenGL Version 2.1 supported!\n");
		}else  printf("OpenGL Version 3.1 supported!\n");
	}else  printf("OpenGL Version 4.5 supported!\n");


	const GLubyte* glVersion = glGetString(GL_VERSION);
	printf("Graphics Driver: %s\n", glVersion);

	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	printf("GLSL Version: %s\n", glslVersion);


	if (GLEW_ARB_vertex_array_object)
		printf("genVertexArrays supported\n");
	if (GLEW_APPLE_vertex_array_object)
		printf("genVertexArrayAPPLE supported\n");
}

void Core::run() {

	init();

	//Set some testing defaults
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLineWidth(3);
	
	
	prog.createShaderProgram("Shaders/passthrough.vert", "Shaders/passthrough.frag");



	orthoID = glGetUniformLocation(prog.id(), "ortho");

	color col;
	col.set(1.0f, 1.0f, 0.0f, 1.0f);

	triangle.create(0, 0, 100, 100, col, prog);
	
	while (currentState != GameState::EXIT) {

		update();

		render();

	}


}


void Core::render() {
	
	glViewport(0, 0, window.getWidth(), window.getHeight());
	glClearColor(.2, .2, .2, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	prog.use();
	
	
	glm::mat4 ortho = glm::ortho(-window.getRatio(), window.getRatio(), -1.f, 1.f, -1.f, 1.f);
	//cam.translate(0.01f, 0, 0);
	cam.translate(.5f, 0.0f,0);
	glUniformMatrix4fv(orthoID, 1, GL_FALSE, glm::value_ptr(cam.getMat()));

	//glBindVertexArray(arrayID);
	triangle.draw();
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	//glBindVertexArray(0);
	prog.unuse();


	window.swapBuffer();
}

void Core::update() {


	cam.update();
	listener.update(currentState);


}



Core::~Core()
{

	SDL_Quit();

}
