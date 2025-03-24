#include <iostream>
#include "gl_core.h"
#include "settings.h"
#include "Renderer.hpp"

void renderFrameLoop(Renderer &renderer, GLFWwindow *window);
void init_scene(Scene &scene);
GLFWwindow *init_glfw();

int main()
{
	Renderer    renderer;
	GLFWwindow *window = NULL;

	// set up
	renderer.OutputImage.resize(SCR_WIDTH * SCR_HEIGHT * 3);
	init_scene(renderer.scene);
	window = init_glfw();
	if (window == NULL)
		return (1);
	glfwSetFramebufferSizeCallback(window, resizeCallback);
	resizeCallback(NULL, SCR_WIDTH, SCR_HEIGHT);

	// loop
	renderFrameLoop(renderer, window);

	// terminate
	glfwDestroyWindow(window);
	glfwTerminate();
	return (0);
}
