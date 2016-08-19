#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Figure.h"
#include "Shaders.h"
#include "Window.h"

int main()
{
	Window window(640, 480, "Kurs Opengl 3", false);

	Shaders shaders;
	Slots slots(shaders);

	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle);
	Figure triangleFigure2(triangle);

	glFrontFace(GL_CCW);
	while (!glfwWindowShouldClose(Window::window))
	{
		glUseProgram(Slots::shadersProgram);

		triangleFigure.setPosition(glm::vec3(0.0f, 0.3f, 1.0f));
		triangleFigure.setScale(glm::vec3(0.5f, 0.5f, 0.5f));
		triangleFigure.draw(triangle);

		Window::closeWindow();

		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}

	glfwDestroyWindow(Window::window);

	return 0;
}