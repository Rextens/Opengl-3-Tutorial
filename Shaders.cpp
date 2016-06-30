#include "Shaders.h"



Shaders::Shaders()
{
}


Shaders::~Shaders()
{
}

GLuint Shaders::loadShaders(std::string vertexShader, std::string fragmentShader)
{
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexShaderData;
	std::ifstream vertexShaderFile(vertexShader);

	
	if (!vertexShaderFile)
	{
		std::cout << "Can't open vertex shader" << std::endl;

		return 0;
	}
	
	std::string line;
	while (std::getline(vertexShaderFile, line))
	{
		vertexShaderData += "\n" + line;
	}
	vertexShaderFile.close();

	std::string fragmentShaderData;
	std::ifstream fragmentShaderFile(fragmentShader);

	if (!fragmentShaderFile)
	{
		std::cout << "Can't open fragment shader" << std::endl;

		return 0;
	}
	std::string line2;
	while (std::getline(fragmentShaderFile, line2))
	{
		fragmentShaderData += "\n" + line2;
	}
	fragmentShaderFile.close();

	const char * vertexPtr = vertexShaderData.c_str();
	const char * fragmentPtr = fragmentShaderData.c_str();

	glShaderSource(vertexShaderId, 1, &vertexPtr, NULL);
	glShaderSource(fragmentShaderId, 1, &fragmentPtr, NULL);

	glCompileShader(vertexShaderId);
	glCompileShader(fragmentShaderId);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShaderId);
	glAttachShader(shaderProgram, fragmentShaderId);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	return shaderProgram;
}