#include "Figure.h"
#include "Window.h"

Figure::Figure(Vertices &vertices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vertices.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
	setPosition(glm::vec3(0.0f, 0.0f, 0.0f));

	howManyTriangles = vertices.vertices.size() / 3;
}
Figure::Figure(Vertices &vertices, Textures &textures)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vertices.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, textures.textureCoordsVbo);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(1);

	howManyTriangles = vertices.vertices.size() / 3;

	setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
}


Figure::~Figure()
{
}

void Figure::draw()
{
	transform = glm::translate(glm::mat4(1.0f), newPosition);
	transformRot = glm::rotate(transform, rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
	transformRot = glm::rotate(transformRot, rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
	transformRot = glm::rotate(transformRot, rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
	transformScale = glm::scale(transformRot, scale);

	glUniformMatrix4fv(Slots::tranformMatrix, 1, GL_FALSE, glm::value_ptr(transformScale));
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, howManyTriangles);
}

void Figure::draw(Shaders &shaders, unsigned int texValue)
{
	transform = glm::translate(glm::mat4(1.0f), newPosition);
	transformRot = glm::rotate(transform, rotate.x, glm::vec3(1.0f, 0.0f, 0.0f));
	transformRot = glm::rotate(transformRot, rotate.y, glm::vec3(0.0f, 1.0f, 0.0f));
	transformRot = glm::rotate(transformRot, rotate.z, glm::vec3(0.0f, 0.0f, 1.0f));
	transformScale = glm::scale(transformRot, scale);

	glUniformMatrix4fv(Slots::tranformMatrix, 1, GL_FALSE, glm::value_ptr(transformScale));
	shaders.sendUniform(texValue, Slots::textureSlot);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, howManyTriangles);
}

void Figure::setPosition(glm::vec3 &newPosition)
{
	this->newPosition = newPosition;
}
void Figure::setRotate(glm::vec3 &rotation)
{
	this->rotate = rotation;
}
void Figure::setScale(glm::vec3 &scale)
{
	this->scale = scale;
}