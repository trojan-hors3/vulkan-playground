#include "pipeline.h"

#include <fstream>
#include <stdexcept>
#include <iostream>

namespace VulkanPlayground
{
	Pipeline::Pipeline(Device& device, 
		     	   const std::string& vertFilepath, 
			   const std::string& fragFilepath,
			   const PipelineConfigInfo& configInfo) : _device{device}
	{
		createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
	}

	std::vector<char> Pipeline::readFile(const std::string& filepath)
	{
		std::ifstream file{filepath, std::ios::ate | std::ios::binary};

		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void Pipeline::createGraphicsPipeline(const std::string& vertFilepath,
                                              const std::string& fragFilepath,
					      const PipelineConfigInfo& configInfo)
	{
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "Vertex Shader Code Size: " << vertCode.size() << "\n";
		std::cout << "Fragment Shader Code Size: " << fragCode.size() << "\n";
	}

	void Pipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo {};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
		
		if (vkCreateShaderModule(_device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create shader module");
		}
	}

	PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
	{
		PipelineConfigInfo configInfo {};

		return configInfo;
	}
}
