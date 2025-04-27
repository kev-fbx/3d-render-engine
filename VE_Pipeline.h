#pragma once

#include "ve_device.h"

#include <string>
#include <vector>

namespace VE {
	struct PipelineConfigInfo {

	};

	class VEPipeline {
	public:
		VEPipeline(
			VEDevice &device,
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo &configInfo);
		~VEPipeline() {}

		VEPipeline(const VEPipeline&) = delete;
		void operator=(const VEPipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
	private:
		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipeline (
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo &configInfo);

		void createShaderModule(const std::vector<char>& code, VkShaderModule& shaderModule);

		VEDevice& veDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
} // namespace VE

