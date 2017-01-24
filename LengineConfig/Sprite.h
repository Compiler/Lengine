#pragma once

#include <GL\glew.h>

class Sprite{
public:
	
	
	
	Sprite();
	Sprite(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath);
	
	void init(GLfloat positionX, GLfloat positionY, GLfloat width, GLfloat height, const char* filePath);



	void render();

	~Sprite();


private:
	

};

