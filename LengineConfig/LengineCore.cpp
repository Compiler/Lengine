#include "LengineCore.h"


int state = 0;
SDL_Window *window;

LengineCore::LengineCore()
{
}



void LengineCore::run() {

	init();

	while (state == 0) {


		update();

		render();
	
	}

}



void LengineCore::init() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) std::cout << "Error initializing SDL\n";

	window = SDL_CreateWindow("Temporary", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);
	if (glewInit() != GLEW_OK) std::cout << "Error initializing GLEW\n";
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	SDL_GL_SetSwapInterval(1);


	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);


	GLfloat verts[6] = { -0.5, -0.5, .5, -.5, 0, .5 };
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);



	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);








	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");


	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)0);
	glEnableVertexAttribArray(0);
}


void LengineCore::update() {
	SDL_Event mine;

	while (SDL_PollEvent(&mine) == 1) {
		if (mine.type == SDL_QUIT || mine.key.keysym.sym == SDLK_ESCAPE)
			state = 1;

	}
	


}


void LengineCore::render() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexID);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glFlush();
	
	SDL_GL_SwapWindow(window);
}



LengineCore::~LengineCore()
{
}
