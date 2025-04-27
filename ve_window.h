#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace VE {

	class VEWindow {
	public:
		VEWindow(int w, int h, std::string name);
		~VEWindow();

		bool shouldClose() { return glfwWindowShouldClose(window); }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

		VEWindow(const VEWindow&) = delete;
		VEWindow& operator = (const VEWindow&) = delete;

	private:
		void initWindow();

		const int width;
		const int height;
		std::string windowName;
		GLFWwindow* window;
	};
} // namespace VE