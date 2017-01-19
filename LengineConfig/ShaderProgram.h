#pragma once
#include <string>
#include <GL\glew.h>
#include "IOManager.h"
#include "OrthographicCamera.h"

class ShaderProgram
{
public:
	ShaderProgram();

	void create(const GLchar *vertexFilePath, const GLchar *fragFilePath);


	void useProgram();
	void unuseProgram();
	inline GLint getProgramID() const { return _shaderProgramID; };

	~ShaderProgram();


private:

	IOManager _manager;

	GLint _shaderProgramID;
	GLuint _vertexID, _fragmentID;

	OrthographicCamera cam;
	
};

