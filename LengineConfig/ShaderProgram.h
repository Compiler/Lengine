#pragma once

#include <GL\glew.h>
#include <string>

class ShaderProgram
{
public:
	ShaderProgram();

	void createShaderProgram(const char* vertexShader, const char* fragmentShader);
	void createShaderProgram(std::string vertexFilePath, std::string fragmentFilePath);
	void use();
	void unuse();
	~ShaderProgram();

private:
	void compileShader(GLint id, std::string filePath);
	void checkCompilationStatus();
	void attachShaders();
	void linkProgram();
	void checkLinkingStatus();



	GLuint programID, vertexID, fragmentID;

};

