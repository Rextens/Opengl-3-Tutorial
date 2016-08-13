#include "Figure.h"

GLint Slots::shadersProgram = 0;
GLint Slots::tranformMatrix = 0;

Slots::Slots(Shaders &shaders)
{
	shadersProgram = shaders.loadShaders("vertexShader.vert", "fragmentShader.frag");
	tranformMatrix = glGetUniformLocation(Slots::shadersProgram, "transforms");
}

Figure::Figure(Vertices &vertices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vertices.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
	setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}


Figure::~Figure()
{
}

void Figure::draw(Vertices &vertices)
{
	glUniformMatrix4fv(Slots::tranformMatrix, 1, GL_FALSE, glm::value_ptr(transform));
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertices.vertices.size() / 3);
}
void Figure::setPosition(glm::vec3 &newPosition)
{
	transform = glm::translate(glm::mat4(1.0f), newPosition);
}
void Figure::setRotate(glm::vec3 &rotation)
{
	transform = glm::rotate(transform, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	transform = glm::rotate(transform, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	transform = glm::rotate(transform, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
}
void Figure::setScale(glm::vec3 &scale)
{
	transform = glm::scale(transform, scale);
}
