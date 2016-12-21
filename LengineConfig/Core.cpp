#include "Core.h"

#include "Vertex.h"

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


	/*GLint attrib = prog.getAttribLocation("position");
	GLint at = prog.getAttribLocation("color");


	glGenVertexArrays(1, &arrayID);
	glBindVertexArray(arrayID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);


	Vertex vertices[3];
	vertices[0].setPosition(-.5f, -.5f);
	vertices[0].color.set(1.0f, 0.0f, 0.0f, 1.0f);

	vertices[1].setPosition(0.5f, -0.5f);
	vertices[1].color.set(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2].setPosition(0.0f, 0.5f);
	vertices[2].color.set(0.0f, 0.0f, 1.0f, 1.0f);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(attrib);
	glVertexAttribPointer(attrib, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, position));
	
	glEnableVertexAttribArray(at);
	glVertexAttribPointer(at, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)offsetof(Vertex, color));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);*/
	color col;
	col.set(1, 0, 0, 1);
	tri.create(-0.5, -0.5, 1.0f, 1.0f, col);
	while (currentState != GameState::EXIT) {

		update();

		render();

	}


}


void Core::render() {
	
	glViewport(0, 0, width, height);
	glClearColor(.2, .2, .2, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//prog.use();

	//glBindVertexArray(arrayID);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	//glBindVertexArray(0);

	//prog.unuse();

	tri.draw();

	window.swapBuffer();
}

void Core::update() {

	listener.update(currentState);


}



Core::~Core()
{

	SDL_Quit();

}
