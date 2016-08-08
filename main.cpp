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

	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle);

	Shaders shaders;

	GLint shadersProgram = shaders.loadShaders("vertexShader.vert", "fragmentShader.frag");
	GLint positon = shaders.findUniform("position", shadersProgram);
	GLint colour = shaders.findUniform("colour", shadersProgram);

	glFrontFace(GL_CCW);
	while (!glfwWindowShouldClose(window))
	{
		glUseProgram(shadersProgram);
		shaders.sendUniform(0.1, positon);
		shaders.sendUniform(glm::vec3(0.5, 0.2, 0.6), colour);

		triangleFigure.draw(triangle);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	return 0;
}