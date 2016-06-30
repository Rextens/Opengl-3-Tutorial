#include <GL/glew.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>

#include <iostream>
#include "Figures.h"
#include "Shaders.h"

int main()
{
	if (!glfwInit())
	{
		std::cout << "Error init glfw" << std::endl;

		return 0;
	}
	
	GLFWwindow *window = glfwCreateWindow(800, 600, "Opengl 1", NULL, NULL);
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error init glew" << std::endl;

		return 0;
	}
	Shaders shader;
	GLuint shaderProgram = shader.loadShaders("vertexShader.vert", "fragmentShader.frag");

	Vertices vertices("arrays.txt");
	Figures figures(vertices.board);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shaderProgram);

		figures.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}