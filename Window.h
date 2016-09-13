#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shaders.h"

struct Slots
{
	Slots(Shaders &shaders);
	static GLint shadersProgram;
	static GLint tranformMatrix;
	static GLint viewMatrix;
	static GLint perspectiveMatrix;
	static GLint textureSlot;
	static GLint colour;
};

class Window
{
public:
	static GLFWwindow *window;

	static float width;
	static float height;
	static float aspect;
	static float FOV;
	static float P1;
	static float P2;

	static glm::mat4 perspective;
	static glm::mat4 view;

	static glm::vec3 cameraPosition;
	static glm::vec3 cameraDirection;
	static glm::vec3 cameraRight;
	static glm::vec3 cameraUp;

	Window(float x, float y, std::string title, bool fullscreen);
	~Window();
	static void closeWindow();
	static void moveCamera(Shaders &shaders);
	static void windowSizeCallback(GLFWwindow* /*window*/, int width, int height);
};

