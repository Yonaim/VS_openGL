#include <iostream>
#include "gl_core.h"
#include "settings.h"
#include "Renderer.hpp"

void renderFrameLoop(Renderer &renderer, GLFWwindow *window);
void init_scene(Scene &scene);
GLFWwindow *init_glfw();

void resize_callback(GLFWwindow* window, int width, int height) {
	//glfwSetWindowSize(window, SCR_WIDTH, SCR_HEIGHT);
}


int main()
{
	Renderer    renderer;
	GLFWwindow *window = NULL;

	// set up
	renderer.OutputImage.resize(SCR_WIDTH * SCR_HEIGHT * 3);
	glfwSetErrorCallback(errorCallback);
	init_scene(renderer.scene);
	window = init_glfw();
	if (window == NULL)
		return (1);
	glfwSetFramebufferSizeCallback(window, resize_callback);
	resize_callback(NULL, SCR_WIDTH, SCR_HEIGHT);
	renderer.setupTexture();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	if (renderer.OutputImage.empty())
	{
		std::cerr << "Error: OutputImage is empty!" << std::endl;
	}

	// loop
	renderFrameLoop(renderer, window);

	// terminate
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
