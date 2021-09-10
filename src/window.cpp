#include "window.h"

namespace VulkanPlayground
{
	Window::Window(int width, int height, std::string windowName)
		: m_width{width}, m_height{height}, m_windowName{windowName}	
	{
		initWindow();
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(m_width, m_height, m_windowName.c_str(), nullptr, nullptr);
	}
}
