#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window();
	~Window();

	void setViewport(int width = 0, int height = 0);
	bool setupWindow(int width, int height, const char* title);
	GLFWwindow* getWindow();

	int windowWidth;
	int windowHeight;

private:
	GLFWwindow* m_Window;
};

