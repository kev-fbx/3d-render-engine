#include "VEWindow.h"

namespace VE {

	VEWindow::VEWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	VEWindow::~VEWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VEWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
} // namespace VE