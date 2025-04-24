#pragma once

#include "VEWindow.h"

namespace VE {
	class App {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;
		void run();
	private:
		VEWindow veWindow{WIDTH, HEIGHT, "My First App"};
	};
}