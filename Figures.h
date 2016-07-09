#pragma once

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <vector>

class Figures
{
public:
	Figures(std::vector<GLfloat> &board);
	~Figures();
	void draw();

	GLuint vbo;
	GLuint vao;
};

class Vertices
{
public:
	std::vector<GLfloat> board;

	Vertices(std::string wayToFile);
	~Vertices();
};
