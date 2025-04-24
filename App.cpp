#include "App.h"

namespace VE {

	void App::run() {
		while (!veWindow.shouldClose()) {
			glfwPollEvents();
		}
	}
} // namespace VE