#pragma once

#include "window.h"
#include "pipeline.h"

namespace VulkanPlayground
{
	class App
	{
		public:
			static constexpr int WIDTH = 800;
			static constexpr int HEIGHT = 600;

			void run();
		private:
			Window window{WIDTH, HEIGHT, "Vulkan Playground"};
			Pipeline pipeline{"src/shaders/simple_shader.vert.spv", "src/shaders/simple_shader.frag.spv"};
	};
}
