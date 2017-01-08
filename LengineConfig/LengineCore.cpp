#include "LengineCore.h"



LengineCore::LengineCore()
{
}



void LengineCore::run() {

	init();

	while (true) {


		update();

		render();
	
	}

}


void LengineCore::init() {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) std::cout << "Error initializing SDL\n";

	SDL_Window *window;
	window = SDL_CreateWindow("Temporary", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GL_CreateContext(window);
	if (glewInit() != GLEW_OK) std::cout << "Error initializing GLEW\n";








	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_VERTEX_ARRAY, bufferID);


	GLfloat verts[6] = { -0.5, -0.5, .5, -.5, 0, .5 };
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), (const void*)verts, GL_STATIC_DRAW);



	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);









	GLint shader = glCreateProgram();
	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);

	std::vector<GLchar> source;
	manager.read("Shaders/passthrough.vert", source);

	char *info = new char[source.size()];
	for (int i = 0; i < source.size(); i++)
		info[i] = source[i];
	glShaderSource(vert, 1, const (info, nullptr);

}


void LengineCore::update() {

	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vertexID);

	glDrawArrays(GL_TRIANGLES, 0, 3);


	glFlush();


}


void LengineCore::render() {

}



LengineCore::~LengineCore()
{
}
