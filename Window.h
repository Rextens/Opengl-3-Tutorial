#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

class Window
{
public:
	static GLFWwindow *window;

	Window(float x, float y, std::string title, bool fullscreen);
	~Window();
	static void closeWindow();
};

