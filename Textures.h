#pragma once

#include <GL\glew.h>
#include <FreeImage.h>
#include <iostream>
#include "Vertices.h"

class Textures
{
public:
	Textures(std::string wayToTexture, Vertices &texVertices);
	~Textures();

	GLuint textureCoordsVbo = 0;
};

