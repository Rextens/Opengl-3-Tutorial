#pragma once

#include "Vertices.h"

class Figure
{
public:
	GLuint vao = 0;

	Figure(Vertices &vertices);
	~Figure();
	void draw(Vertices &vertices);
};

