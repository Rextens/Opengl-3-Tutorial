#include "Vertices.h"



Vertices::Vertices(std::string wayToFile)
{
	std::ifstream inputVertices(wayToFile);

	if (!inputVertices)
	{
		std::cout << "Can't find file with wertices" << wayToFile.c_str() << std::endl;
	}
	
	GLfloat inputVert = 0;
	while (inputVertices.good())
	{
		inputVertices >> inputVert;
		vertices.push_back(inputVert);
	}

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
}


Vertices::~Vertices()
{
}
