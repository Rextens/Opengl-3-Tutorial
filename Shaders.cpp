#include "Shaders.h"
#include "Window.h"


Shaders::Shaders()
{
}


Shaders::~Shaders()
{
}
GLint Shaders::loadShaders(std::string vertexShader, std::string fragmentShader)
{
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertexShaderData;

	std::ifstream vertexShaderFile(vertexShader);

	if (vertexShaderFile)
	{
		std::string line;
		while (std::getline(vertexShaderFile, line))
		{
			vertexShaderData += "\n" + line;
		}
	}

	std::string fragmentShaderData;

	std::ifstream fragmentShaderFile(fragmentShader);

	if (fragmentShaderFile)
	{
		std::string line;
		while (std::getline(fragmentShaderFile, line))
		{
			fragmentShaderData += "\n" + line;
		}
	}

	const char * vertexPtr = vertexShaderData.c_str();
	const char * fragmentPtr = fragmentShaderData.c_str();

	glShaderSource(vertexShaderId, 1, &vertexPtr, nullptr);
	glShaderSource(fragmentShaderId, 1, &fragmentPtr, nullptr);

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
GLint Shaders::findUniform(std::string uniformName, GLint &program)
{
	GLint uniform = glGetUniformLocation(program, uniformName.c_str());

	if (uniform == -1)
	{
		std::cout << "Can't find uniform " << uniformName.c_str() << std::endl;
	}
	else
	{
		return uniform;
	}
}
void Shaders::sendUniform(float value, GLint &program)
{
	glUniform1f(program, value);
}
void Shaders::sendUniform(glm::vec3 &value, GLint &program)
{
	glUniform3f(program, value.x, value.y, value.z);
}
void Shaders::sendUniform(glm::mat4 &value, GLint &program)
{
	glUniformMatrix4fv(program, 1, GL_FALSE, glm::value_ptr(value));
}