#include "app.h"

namespace VulkanPlayground
{
	void App::run()
	{
		while (!window.shouldClose())
		{
			glfwPollEvents();
		}
	}
}
