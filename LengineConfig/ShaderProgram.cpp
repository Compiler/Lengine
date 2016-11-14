#include "ShaderProgram.h"



ShaderProgram::ShaderProgram() : programID(0), vertexID(0), fragmentID(0)
{
}
/*
	Compiles the given shader program with the given file paths for vertex and fragment
*/
void ShaderProgram::compile(std::string vertex, std::string fragment) {
	
	programID = glCreateProgram();

	vertexID = glCreateShader(GL_VERTEX_SHADER);
	fragmentID = glCreateShader(GL_FRAGMENT_SHADER);



	compileShader(vertex, vertexID);
	compileShader(fragment, fragmentID);

	

}

/*
	Compiles each shader individually
*/
void ShaderProgram::compileShader(std::string filePath, GLuint shaderID) {
		
	std::ifstream file(filePath);
	if (file.fail()) {
		perror(filePath.c_str());
		Error::throwException(Error::ExceptionType::GENERAL, "couldn't load file", true);
	}
	std::string fileContents = "";
	std::string line;

	while (std::getline(file, line)) {
		fileContents += line + "\n";
	}
	file.close();
	//std::cout << "hello" << fileContents;
	const char* contentsPointer = fileContents.c_str();
	glShaderSource(shaderID, 1, &contentsPointer, nullptr);

	glCompileShader(shaderID);

	//check for errors
	GLint success = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE) {

		GLint maxLength = 0;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);


		glDeleteShader(shaderID);

		std::printf("%s\n", &(errorLog[0]));
		Error::throwException(Error::ExceptionType::GENERAL, "Shader failed to compile", true);
	}


}

/*
	Links the shaders to the shader program id created
*/
void ShaderProgram::linkShaders() {

	glAttachShader(programID, vertexID);
	glAttachShader(programID, fragmentID);

	glLinkProgram(programID);

	GLint isLinked = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, (int *)&isLinked);

	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(programID, maxLength, &maxLength, &infoLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(programID);
		//Don't leak shaders either.
		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);

		std::printf("%s\n", &(infoLog[0]));
		Error::throwException(Error::ExceptionType::GENERAL, "Shader failed to link", true);
	}

	glDetachShader(programID, vertexID);
	glDetachShader(programID, fragmentID);
	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}


/*
	Allows for binding of attributes in the shader
*/
void ShaderProgram::bindAttrib(const std::string& attributeName, GLuint indexOfAttribute) {
	glBindAttribLocation(programID, indexOfAttribute, attributeName.c_str());
	numOfAttribs++;

}

/*
	Uses the shader program
*/
void ShaderProgram::use() {

	glUseProgram(programID);

	for (int i = 0; i < numOfAttribs; i++)
		glEnableVertexAttribArray(i);

}
/*
	Ends the shader program
*/

void ShaderProgram::unuse() {

	glUseProgram(0);
	for (int i = 0; i < numOfAttribs; i++)
		glDisableVertexAttribArray(i);

}
/*
	Returns the id location of the searched for uniform variable in the
	current shader program
*/

GLint ShaderProgram::getUniformLocation(std::string name) {
	return glGetUniformLocation(programID, name.c_str());
	
}

ShaderProgram::~ShaderProgram()
{
}
