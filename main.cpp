#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Figure.h"
#include "Shaders.h"
#include "Window.h"

int main()
{
	Window window(640, 480, "Kurs Opengl 3", !false);

	Shaders shaders;
	Slots slots(shaders);

	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle);

	glFrontFace(GL_CW);
	while (!glfwWindowShouldClose(Window::window))
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(Slots::shadersProgram);

		triangleFigure.setPosition(glm::vec3(0.0f, 0.3f, 1.0f));
		triangleFigure.setScale(glm::vec3(0.5f, 0.5f, 0.5f));
		triangleFigure.draw(triangle);

		Window::moveCamera(shaders);
		Window::closeWindow();

		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}

	glfwDestroyWindow(Window::window);

	return 0;
}