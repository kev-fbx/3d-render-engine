#pragma once

#include "VEWindow.h"
#include "VE_Pipeline.h"

namespace VE {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();
	private:
		VEWindow veWindow{WIDTH, HEIGHT, "My First App"};
		VEPipeline vePipeline{ "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv" };
	};
}