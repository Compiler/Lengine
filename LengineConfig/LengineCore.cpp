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

	glClearColor(0.075f, 0.075f, 0.075f, 1.0f);
	
	cam.init(640.0f, 480.0f);
	cam.print();

	rend.init();


	sprite.init(0.0f, 0.0f, 100.0f, 100.0f, "Textures/woodcrate.bmp");
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


	rend.begin();
	cam.sendToShader(rend.getShaderID());
	rend.setColor(125, 123, 125, 2);
	int incrementer = 10;
	for(int i = 0; i < 640; i += incrementer){
		for(int k = 0; k < 480; k += incrementer){
			rend.drawRectangle(i + k * cos( atan2(k, i) * 10) * cos(deltaTime), k, 5, 5);
			rend.setColor(i * (i+k), 255 - 255 * cos(k * i), 255*sin(i * deltaTime), 255);
			
		}
	}
	//rend.drawRectangle(400.0f, 200.0f, 100.0f, 100.0f);
	rend.end();

	deltaTime = getDelta();
	
	//sprite.render(cam);

	glFlush();
	
	SDL_GL_SwapWindow(window);
}


GLfloat LengineCore::getDelta(){

	static auto timePrev = std::chrono::high_resolution_clock::now();

	std::chrono::time_point<std::chrono::steady_clock> current = std::chrono::high_resolution_clock::now();

	std::chrono::nanoseconds timeDiff = std::chrono::duration_cast<std::chrono::nanoseconds>(current - timePrev);


	GLfloat delta = timeDiff.count();

	delta /= 1000000000;

	timePrev = current;
	deltaTime = delta;
	return delta;
}


LengineCore::~LengineCore()
{
}
