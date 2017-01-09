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
	glBindBuffer(GL_VERTEX_ARRAY, bufferID);


	GLfloat verts[6] = { -0.5, -0.5, .5, -.5, 0, .5 };
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), (const void*)verts, GL_STATIC_DRAW);



	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);









	GLint shader = glCreateProgram();
	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);



	std::string vertInfo, fragInfo;
	manager.read("Shaders/passthrough.vert", vertInfo);
	const GLchar *source = &vertInfo.c_str()[0];
	manager.read("Shaders/passthrough.frag", fragInfo);
	const GLchar *fragSource = &fragInfo.c_str()[0];


	glShaderSource(vert, 1, &source, nullptr);
	glShaderSource(frag, 1, &fragSource, nullptr);

	glCompileShader(vert);
	glCompileShader(frag);
	GLint outcome = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &outcome);
	if (outcome == GL_FALSE) {
		GLchar message[356];
		glGetShaderInfoLog(shader, sizeof(message), 0, &message[0]);
		std::cout << message;
		SDL_Delay(1000);
	}

	glAttachShader(shader, vert);
	glAttachShader(shader, frag);

	glLinkProgram(shader);



	glUseProgram(shader);


	glVertexAttribPointer(vertexID, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)0);
	glEnableVertexAttribArray(vertexID);
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
