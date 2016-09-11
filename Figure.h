#pragma once

#include "Vertices.h"
#include "Shaders.h"
#include "Textures.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Figure
{
	glm::mat4 transform = glm::mat4(1.0f);
	glm::mat4 transformRot = glm::mat4(1.0f);
	glm::mat4 transformScale = glm::mat4(1.0f);

	glm::vec3 scale = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 rotate = glm::vec3(0.0f, 0.0f, 0.0f);

	unsigned int howManyTriangles = 0;
public:
	GLuint vao = 0;
	glm::vec3 newPosition = glm::vec3(0.0f, 0.0f, 0.0f);

	Figure(Vertices &vertices);
	Figure(Vertices &vertices, Textures &textures);
	~Figure();
	void draw();
	void draw(Shaders &shaders, unsigned int texValue);
	void setPosition(glm::vec3 &newPosition);
	void setRotate(glm::vec3 &rotation);
	void setScale(glm::vec3 &scale);
};

