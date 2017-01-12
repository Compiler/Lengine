#include "ShaderProgram.h"
#include <iostream>

ShaderProgram::ShaderProgram()
{
}


void ShaderProgram::create(const GLchar *vertexFilePath, const GLchar *fragFilePath) {
	
	_shaderProgramID = glCreateProgram();
	_vertexID = glCreateShader(GL_VERTEX_SHADER);
	_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);


	std::string vertInfo, fragInfo;


	_manager.read(vertexFilePath, vertInfo);
	const GLchar *source = &vertInfo.c_str()[0];
	_manager.read(fragFilePath, fragInfo);
	const GLchar *fragSource = &fragInfo.c_str()[0];


	glShaderSource(_vertexID, 1, &source, nullptr);
	glShaderSource(_fragmentID, 1, &fragSource, nullptr);



	glCompileShader(_vertexID);
	//Now check if vertex shader compiled correctly
	GLint isCompiled = 0;
	glGetShaderiv(_vertexID, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(_vertexID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(_vertexID, maxLength, &maxLength, &errorLog[0]);


		std::cout << "\nError in compiling Vertex Shader:\n";
		for (int i = 0; i < errorLog.size(); i++) {
			std::cout << errorLog[i];
		}

		glDeleteShader(_vertexID);
		glDeleteShader(_fragmentID);
		return;
	}


	glCompileShader(_fragmentID);

	//Now check if fragment shader compiled correctly
	isCompiled = 0;
	glGetShaderiv(_fragmentID, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(_fragmentID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(_fragmentID, maxLength, &maxLength, &errorLog[0]);

		std::cout << "\nError in compiling Fragment Shader:\n";
		for (int i = 0; i < errorLog.size(); i++) {
			std::cout << errorLog[i];
		}
		glDeleteShader(_vertexID);
		glDeleteShader(_fragmentID);
		return;
	}


	glAttachShader(_shaderProgramID, _vertexID);
	glAttachShader(_shaderProgramID, _fragmentID);

	glLinkProgram(_shaderProgramID);

	glUseProgram(_shaderProgramID);




	GLuint uniformID = glGetUniformBlockIndex(_shaderProgramID, "UniformBlock");
	GLint bufferSize;
	glGetActiveUniformBlockiv(_shaderProgramID, uniformID, GL_UNIFORM_BLOCK_DATA_SIZE, &bufferSize);

	GLubyte *buffer = (GLubyte *)malloc(bufferSize);
	if (buffer == NULL) {
		fprintf(stderr, "Unable to allocate buffer\n");
		exit(EXIT_FAILURE);
	}else {
		
		const char* names[] = {"location", "radius", "enabled"};

		const GLuint indiceCount = 3;
		GLuint indices[indiceCount];

		glGetUniformIndices(_shaderProgramID, indiceCount, names, indices);
		std::cout << "********Uniform Layouts*******\n";
		for (int i = 0; i < indiceCount; i++)
			std::cout << names[i] << " located at " << indices[i] << "\n";

		GLint offsets[4];
		glGetActiveUniformsiv(_shaderProgramID, indiceCount, indices, GL_UNIFORM_OFFSET, offsets);

		std::cout << "Offsets: \n";
		for (int i = 0; i < indiceCount; i++) {
			std::cout << "Number " << i << "~ "<< names[i] << ":" << offsets[i] << "\n";
		}

		GLfloat location[4] = { -0.5f, 0.0f, 0.0f, 0.0f };
		GLfloat radius = 0.5f;
		GLboolean enabled = true;
		//memcpy(buffer + offsets[0], cols, sizeof(GLfloat) * 4);
		memcpy(buffer + offsets[0], location, sizeof(GLfloat) * 4);
		memcpy(buffer + offsets[1], &radius, sizeof(GLfloat) * 1);
		memcpy(buffer + offsets[2], &enabled, sizeof(GLboolean) * 1);



		GLuint ubo;
		glGenBuffers(1, &ubo);
		glBindBuffer(GL_UNIFORM_BUFFER, ubo);
		glBufferData(GL_UNIFORM_BUFFER, bufferSize, buffer, GL_DYNAMIC_DRAW);

		glBindBufferBase(GL_UNIFORM_BUFFER, uniformID, ubo);
	}


}


void ShaderProgram::useProgram() {
	glUseProgram(_shaderProgramID);
}

void ShaderProgram::unuseProgram() {
	glUseProgram(0);
}

ShaderProgram::~ShaderProgram()
{
}
