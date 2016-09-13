#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "Figure.h"
#include "Shaders.h"
#include "Window.h"
#include "Textures.h"
#include <FreeImage.h>

int main()
{
	Window window(640, 480, "Kurs Opengl 3", false);

	Shaders shaders;
	Slots slots(shaders);

	glActiveTexture(GL_TEXTURE0);
	Textures("texture.jpg");

	Vertices textureVert("textureCoords.txt");
	Vertices triangle("firstTriangle.raw");
	Figure triangleFigure(triangle, textureVert);

	glFrontFace(GL_CW);

	float i = 0;

	while (!glfwWindowShouldClose(Window::window))
	{
		i += 0.0001;
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(Slots::shadersProgram);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		triangleFigure.setPosition(glm::vec3(0.0f, 0.3f, 1.0f));
		triangleFigure.setScale(glm::vec3(0.5f, 0.5f, 0.5f));
		triangleFigure.setColour(glm::vec4(0.5f, i, 0.4f, 1.0f));
		triangleFigure.draw(shaders, 0);

		Window::moveCamera(shaders);
		Window::closeWindow();

		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}

	glfwDestroyWindow(Window::window);

	return 0;
}