#include "gl_core.h"
#include "Renderer.hpp"

static void computeRayTracing(Renderer &renderer)
{
	std::cout << "Starting ray tracing..." << std::endl;
	renderer.rayTrace();
	std::cout << "Ray tracing complete!" << std::endl;

	//glBindTexture(GL_TEXTURE_2D, renderer.textureID);
	//glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, SCR_WIDTH, SCR_HEIGHT, GL_RGB,
	//				GL_UNSIGNED_BYTE, renderer.output);
}

void renderFrameLoop(Renderer &renderer, GLFWwindow *window)
{
	bool needRecompute = true;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawPixels(SCR_WIDTH, SCR_HEIGHT, GL_RGB, GL_FLOAT, &renderer.OutputImage[0]);


		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS
			|| glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
