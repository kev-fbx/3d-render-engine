#include "ve_pipeline.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace VE {

	VEPipeline::VEPipeline(
		VEDevice& device,
		const std::string& vertFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& configInfo)
		: veDevice{ device } {
		createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
	}

	std::vector<char> VEPipeline::readFile(const std::string& filePath) {
		std::ifstream file{ filePath, std::ios::ate | std::ios::binary };

		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + filePath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void VEPipeline::createGraphicsPipeline(
			const std::string& vertFilePath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << "Vertex shader code size: " << vertCode.size() << '\n';
		std::cout << "Fragment shader code size: " << fragCode.size() << '\n';
	}

	void VEPipeline::createShaderModule(const std::vector<char>& code, VkShaderModule& shaderModule) {
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(veDevice.device(), &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create shader module");
		}
	}

	PipelineConfigInfo VEPipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
		PipelineConfigInfo configInfo{};
		return configInfo;
	}
} // namespace VE