#pragma once

#include <GL\glew.h>
#include <fstream>
#include <iostream>
#include <string>

class Shaders
{
public:
	Shaders();
	~Shaders();
	GLuint loadShaders(std::string vertexShader, std::string fragmentShader);
};

