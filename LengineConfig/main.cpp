
#include <iostream>

#include <GL\glew.h>
#include <SDL\SDL.h>


GLuint vertexID, bufferID;



void init(void);
void initVertexArrayObject(void);

//start of app
int main(int argc, char** argv){

	init();
	initVertexArrayObject();
	
	system("PAUSE");
	return 0;
}


void init(void) {

	

}



void initVertexArrayObject(void) {
	

	
	glGenVertexArrays(1, &vertexID);
	glBindVertexArray(vertexID);

	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_VERTEX_ARRAY, bufferID);


	GLfloat verts[6] = {-0.5, -0.5, .5, -.5, 0, .5};
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), (const void*)verts, GL_STATIC_DRAW);
}