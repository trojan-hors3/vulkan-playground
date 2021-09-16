#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace VulkanPlayground
{
	class Window
	{
		public:
			Window(int width, int height, std::string windowName);
			~Window();

			Window(const Window &) = delete;
			Window &operator=(const Window &) = delete;

			bool shouldClose() { return glfwWindowShouldClose(window); };

			void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		private:
			void initWindow();

			const int m_width;
			const int m_height;

			std::string m_windowName;

			GLFWwindow* window;
	};
}
