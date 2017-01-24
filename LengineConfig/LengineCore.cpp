#include "LengineCore.h"

#include "ImageLoader.h"
#include "pico.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <lml\Vector3.h>	

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

	glewExperimental = GL_TRUE;
	SDL_GL_SetSwapInterval(1);



	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);

	GLfloat bottomLeft = 90.0f;
	GLfloat dim = 640.0f / 4.0f;
	Vector3 verts[4] = {
		Vector3(bottomLeft, bottomLeft, 0.0),// Bottom left
		Vector3(bottomLeft + dim, bottomLeft, 0.0), // Bottom right
		Vector3(bottomLeft, bottomLeft + dim, 0.0), // Top left
		Vector3(bottomLeft + dim, bottomLeft + dim, 0.0)   // Top right
	};
	//0, 1, 2, 2, 3, 1
	GLfloat r, g, b;
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	GLfloat color[4 * 3 * 2] = {
		r, g, b, 1.0f,
		r, g, b, 1.0f,
		r, g, b, 1.0f,
		r, g, b, 1.0f,
		r, g, b, 1.0f,
		r, g, b, 1.0f};

	GLfloat tex[8] = {
	0.0f, 0.0f, 
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f
	};

	GLfloat norm[8] = {
	
	};

	
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts) + sizeof(color) + sizeof(tex), nullptr, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verts), verts);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(verts), sizeof(color), color);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(verts) + sizeof(color), sizeof(tex), tex);


	glClearColor(0.075f, 0.075f, 0.075f, 1.0f);



	shader.create("Shaders/passthrough.vert", "Shaders/passthrough.frag");


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, NULL);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (const GLvoid *)(sizeof(verts)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 0, (const GLvoid *)(sizeof(verts) + sizeof(color)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);


	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

	GLuint indices[6] = {
		//3,1,2,0
		0,1,2,  2,3,1
	};
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	
	unsigned long width, height;
	
	LoadBMP("Textures/woodcrate.bmp", width, height, texture);
	
	cam.init(640.0f, 480.0f);
	cam.print();

	rend.init();
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


	shader.useProgram();

	glBindTexture(GL_TEXTURE_2D, texture);
	
	glBindVertexArray(vertexID);

	cam.update();
	cam.sendToShader(shader.getProgramID());
	

	glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, 0);
	
	
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	shader.unuseProgram();

	rend.begin();
	cam.sendToShader(rend.getShaderID());
	rend.setColor(0.0f, 1.0f, 0.0f, 1.0f);
	rend.drawTriangle(50.0f, 100.0f, 200.0f, 100.0f, 150.0f, 300.0f);
	rend.setColor(1.0f, 0.0f, 0.0f, 1.0f);
	rend.drawTriangle(300.0f, 100.0f, 400.0f, 100.0f, 350.0f, 300.0f);

	//rend.drawTriangle(100.0f, 100.0f, 200.0f, 100.0f, 150.0f, 300.0f);
	//rend.drawTriangle(100.0f, 100.0f, 200.0f, 100.0f, 150.0f, 300.0f);
	rend.end();
	glFlush();
	
	SDL_GL_SwapWindow(window);
}



LengineCore::~LengineCore()
{
}
