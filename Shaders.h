#pragma once

#include <GL\glew.h>
#include <glm.hpp>
#include <fstream>
#include <iostream>
#include <string>

class Shaders
{
public:
	Shaders();
	~Shaders();
	GLuint loadShaders(std::string vertexShader, std::string fragmentShader);

	GLint loadUniform(GLuint &shaders, std::string name)
	{
		return glGetUniformLocation(shaders, name.c_str());
	}
	void sendUniform(float type, GLint &unform)
	{
		glUniform1f(unform, type);
	}
	void sendUniform(glm::vec2 &type, GLint &unform)
	{
		glUniform2f(unform, type.x, type.y);
	}
	void sendUniform(glm::vec3 &type, GLint &unform)
	{
		glUniform3f(unform, type.x, type.y, type.z);
	}
};

