#pragma once

#include "ve_window.h"
#include "ve_pipeline.h"
#include "ve_device.h"

namespace VE {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		VEWindow veWindow{ WIDTH, HEIGHT, "First App" };
		VEDevice veDevice{ veWindow };
		VEPipeline vePipeline{
			veDevice,
			"shaders/simple_shader.vert.spv",
			"shaders/simple_shader.frag.spv",
			VEPipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}