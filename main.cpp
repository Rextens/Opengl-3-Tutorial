#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Figure.h"
#include "Shaders.h"

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
	Shaders shaders;
	Slots slots(shaders);

	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle);
	Figure triangleFigure2(triangle);

	glFrontFace(GL_CCW);
	while (!glfwWindowShouldClose(window))
	{
		glUseProgram(Slots::shadersProgram);

		triangleFigure.setPosition(glm::vec3(0.0f, 0.3f, 1.0f));
		triangleFigure.setScale(glm::vec3(0.5f, 0.5f, 0.5f));
		triangleFigure.draw(triangle);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	return 0;
}