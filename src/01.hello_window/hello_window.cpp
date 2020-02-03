// 01_hello_window.cpp

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <vector>

int main() {
	// glfw ��ʼ��
	if (glfwInit() == GLFW_FALSE)
	{
		std::cout << "Failed to init GLFW!\n";
		return -1;
	}

	// ��������
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create window using GLFW!\n";
		return -1;
	}

	// ö��ʵ����չ����
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::cout << extensionCount << " extensions supported" << std::endl;

	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
	std::cout << "available extensions:" << std::endl;

	for (const auto& extension : extensions) {
		std::cout << "\t" << extension.extensionName << std::endl;
	}

	// ���� glm
	glm::mat4 matrix;
	glm::vec4 vec;
	auto test = matrix * vec;

	// ��Ϸѭ��
	while (!glfwWindowShouldClose(window)) {

		// if Esc is pressed, close the window
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);

		// poll
		glfwPollEvents();
	}

	// ���ٴ���
	glfwDestroyWindow(window);

	// �ͷ�����GLFW��Դ
	glfwTerminate();

	return 0;
}