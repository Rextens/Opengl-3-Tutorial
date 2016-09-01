#include "Window.h"

GLFWwindow *Window::window;

float Window::width = 0;
float Window::height = 0;
float Window::aspect = 0;
float Window::FOV = 90.0f;
float Window::P1 = 0.1f;
float Window::P2 = 20.0f;


glm::mat4 Window::perspective = glm::mat4(1.0f);
glm::mat4 Window::view = glm::mat4(1.0f);

glm::vec3 Window::cameraPosition = glm::vec3(0.0f, 0.0f, 2.0f);
glm::vec3 Window::cameraDirection = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Window::cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 Window::cameraUp = glm::cross(Window::cameraRight, Window::cameraDirection);

GLint Slots::shadersProgram = 0;
GLint Slots::tranformMatrix = 0;
GLint Slots::perspectiveMatrix = 0;
GLint Slots::viewMatrix = 0;

Slots::Slots(Shaders &shaders)
{
	shadersProgram = shaders.loadShaders("vertexShader.vert", "fragmentShader.frag");
	tranformMatrix = glGetUniformLocation(Slots::shadersProgram, "transforms");
	viewMatrix = glGetUniformLocation(Slots::shadersProgram, "view");
	perspectiveMatrix = glGetUniformLocation(Slots::shadersProgram, "perspective");
}

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
		width = videomod->width;
		height = videomod->height;
		window = glfwCreateWindow(videomod->width, videomod->height, title.c_str(), glfwGetPrimaryMonitor(), nullptr);
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error init glew" << std::endl;	
	}

	glfwSetWindowSizeCallback(window, windowSizeCallback);
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
void Window::moveCamera(Shaders &shaders)
{
	view = glm::lookAt(cameraPosition, cameraPosition + cameraDirection, cameraUp);

	if (glfwGetKey(window, GLFW_KEY_W))
	{
		cameraPosition.y += 0.01;
	}
	if (glfwGetKey(window, GLFW_KEY_S))
	{
		cameraPosition.y -= 0.01;
	}
	if (glfwGetKey(window, GLFW_KEY_A))
	{
		cameraPosition.x -= 0.01;
	}
	if (glfwGetKey(window, GLFW_KEY_D))
	{
		cameraPosition.x += 0.01;
	}

	shaders.sendUniform(view, Slots::viewMatrix);
	shaders.sendUniform(perspective, Slots::perspectiveMatrix);
}
void Window::windowSizeCallback(GLFWwindow* /*window*/, int widthWindow, int heightWindow)
{
	width = widthWindow;
	height = heightWindow;

	aspect = 16.0f / 9.0f;
	perspective = glm::perspective(glm::radians(FOV), aspect, P1, P2);
}