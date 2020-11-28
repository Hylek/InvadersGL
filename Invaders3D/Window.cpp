#include "Window.h"

Window::Window()
{
	windowHeight = 0;
	windowWidth = 0;
	m_Window = NULL;
}

Window::~Window()
{

}

void Window::setViewport(int width, int height)
{
	int finalWidth = width == 0 ? windowWidth : width;
	int finalHeight = height == 0 ? windowHeight : height;

	glViewport(0, 0, finalWidth, finalHeight);

	// Not sure why this won't accept class bound functions as the callback use lambda for now. 
	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		});
}

bool Window::setupWindow(int width, int height, const char* title)
{
	windowWidth = width;
	windowHeight = height;

	m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (m_Window == NULL)
	{
		std::cout << "ERROR: Could not create GLFW window!" << std::endl;

		return false;
	}
	glfwMakeContextCurrent(m_Window);

	return true;
}

GLFWwindow* Window::getWindow()
{
	return m_Window;
}
