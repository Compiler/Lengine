#include "LengineCore.h"

#include "ImageLoader.h"
#include "pico.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
GLuint texture;
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


	GLfloat verts[4 * 2 * 3] = { -0.5, -0.5, 0.0, 1.0,// bottom left
							.5, -.5, 0.0, 1.0,    // bottom right
							-.5, .5, 0.0, 1.0,    // top left
							0.5, 0.5, 0.0, 1.0,
							.5, -.5, 0.0, 1.0,    // bottom right
							-.5, .5, 0.0, 1.0,    // top left// top right
							};
	GLfloat color[4 * 3 * 2] = {
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f, 
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f };

	GLfloat tex[8] = {
	0.0f, 0.0f, 
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts) + sizeof(color) + sizeof(tex), nullptr, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(verts), sizeof(color), color);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(verts) + sizeof(color), sizeof(tex), tex);


	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);








	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");


	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, NULL);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (const GLvoid *)(sizeof(verts)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (const GLvoid *)(sizeof(verts) + sizeof(color)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	GLuint indices[4] = {
		3,1,2,0
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	
	unsigned long width, height;
	
	LoadBMP("Textures/RGB.bmp", width, height, texture);



	glm::mat4 proj = glm::perspective(45.0f, (float)1 / (float)1, 0.1f, 100.0f);

	GLint loc = glGetUniformLocation(shader.getProgramID(), "transform");
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(proj));
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

	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBindVertexArray(vertexID);

	glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glFlush();
	
	SDL_GL_SwapWindow(window);
}



LengineCore::~LengineCore()
{
}
