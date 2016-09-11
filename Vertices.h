#pragma once

#include <GL\glew.h>
#include <iostream>
#include <vector>
#include <fstream>

class Vertices
{
public:
	Vertices(std::string wayToFile);
	~Vertices();
	GLuint vbo = 0;

	std::vector<GLfloat> vertices;
};

