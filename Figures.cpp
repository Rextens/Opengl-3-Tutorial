#include "Figures.h"



Figures::Figures(std::vector<GLfloat> &board)
{
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * board.size(), board.data(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao); 
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
}
Figures::~Figures()
{
}
void Figures::draw()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
Vertices::Vertices(std::string wayToFile)
{
	std::ifstream file(wayToFile);

	if (!file)
	{
		std::cout << "Error with load vertices" << std::endl;

		return;
	}

	while (!file.eof())
	{
		GLfloat temp;
		file >> temp;
		board.push_back(temp);
	}
}
Vertices::~Vertices()
{

}