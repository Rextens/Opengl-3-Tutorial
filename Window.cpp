#include "Window.h"

GLFWwindow *Window::window;


Window::Window(float x, float y, std::string title, bool fullscreen)
{
	
	if (glfwInit() == 0)
	{
		std::cout << "Error init glfw" << std::endl;
	}
	if (!fullscreen)
	{
		window = glfwCreateWindow(x, y, title.c_str(), nullptr, nullptr);
	}
	else
	{
		const GLFWvidmode *videomod = glfwGetVideoMode(glfwGetPrimaryMonitor());
		window = glfwCreateWindow(videomod->width, videomod->height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error init glew" << std::endl;
	}
}


Window::~Window()
{
}

void Window::closeWindow()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}