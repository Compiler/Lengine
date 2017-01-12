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

GLuint ebo;

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


	GLfloat verts[3*2*4] = { -0.5, -0.5, 0.0, 1.0,// bottom left
							.5, -.5, 0.0, 1.0,    // bottom right
							-.5, .5, 0.0, 1.0,    // top left

							0.5, 0.5, 0.0, 1.0,   // top right
							.5, -.5, 0.0, 1.0,    // bottom right
							-.5, .5, 0.0, 1.0,    // top left
		//0,1,3,2,0
							};
	GLfloat color[4 * 3 * 2] = {
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f };

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts) + sizeof(color), nullptr, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(verts), sizeof(color), color);


	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);








	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");


	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)* 4, NULL);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 4, (const GLvoid *)sizeof(verts));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);


	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	GLuint indices[4] = {
		0,1,3,2
	};

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
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

	glBindVertexArray(ebo);

	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_INT, 0);

	glFlush();
	
	SDL_GL_SwapWindow(window);
}



LengineCore::~LengineCore()
{
}
