#pragma once

#include <GL\glew.h>
#include <iostream>
#include <fstream>
#include <string>
#include <glm\glm.hpp>

class Shaders
{
public:
	Shaders();
	~Shaders();
	GLint loadShaders(std::string vertexShader, std::string fragmentShader);
	GLint findUniform(std::string uniformName, GLint &program);
	void sendUniform(float value, GLint &program);
	void sendUniform(glm::vec3 &value, GLint &program);
	void sendUniform(glm::mat4 &value, GLint &program);
};

