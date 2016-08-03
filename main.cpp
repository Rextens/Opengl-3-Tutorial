#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Figure.h"

int main()
{
	if (glfwInit() == 0)
	{
		std::cout << "Error init glfw" << std::endl;
	}

	GLFWwindow *window = glfwCreateWindow(640, 480, "Opengl 3 Tutorial", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error init glew" << std::endl;
	}

	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle);

	glFrontFace(GL_CCW);
	while (!glfwWindowShouldClose(window))
	{
		triangleFigure.draw(triangle);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	return 0;
}