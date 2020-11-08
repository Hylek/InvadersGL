#include "Window.h"

Window::Window()
{
	m_Height = 0;
	m_Width = 0;
	m_Window = NULL;
}

Window::~Window()
{

}

void Window::setViewport(int width, int height)
{
	int finalWidth = width == 0 ? m_Width : width;
	int finalHeight = height == 0 ? m_Height : height;

	glViewport(0, 0, finalWidth, finalHeight);

	// Not sure why this won't accept class bound functions as the callback use lambda for now. 
	glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		});
}

bool Window::setupWindow(int width, int height, const char* title)
{
	m_Width = width;
	m_Height = height;

	m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
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
