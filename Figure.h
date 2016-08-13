#pragma once

#include "Vertices.h"
#include "Shaders.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Slots
{
	Slots(Shaders &shaders);
	static GLint shadersProgram;
	static GLint tranformMatrix;
};

class Figure
{
	glm::mat4 transform = glm::mat4(1.0f);
public:
	GLuint vao = 0;

	Figure(Vertices &vertices);
	~Figure();
	void draw(Vertices &vertices);
	void setPosition(glm::vec3 &newPosition);
	void setRotate(glm::vec3 &rotation);
	void setScale(glm::vec3 &scale);
};

