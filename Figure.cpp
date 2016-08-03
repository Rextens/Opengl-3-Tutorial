#include "Figure.h"



Figure::Figure(Vertices &vertices)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vertices.vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
}


Figure::~Figure()
{
}

void Figure::draw(Vertices &vertices)
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertices.vertices.size() / 3);
}
