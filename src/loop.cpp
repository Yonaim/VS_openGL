#include "gl_core.h"
#include "Renderer.hpp"
#include <cstring>

static void computeRayTracing(Renderer &renderer)
{
	std::cout << "Starting ray tracing..." << std::endl;
	renderer.rayTrace();
	std::cout << "Ray tracing complete!" << std::endl;
}

static void flipImageVertically(std::vector<float> &image, int width, int height)
{
    int rowSize = width * 3; // RGB
    std::vector<float> temp(rowSize);

    for (int y = 0; y < height / 2; ++y)
    {
        int topIndex = y * rowSize;
        int bottomIndex = (height - 1 - y) * rowSize;

        std::memcpy(temp.data(), &image[topIndex], rowSize * sizeof(float));
        std::memcpy(&image[topIndex], &image[bottomIndex], rowSize * sizeof(float));
        std::memcpy(&image[bottomIndex], temp.data(), rowSize * sizeof(float));
    }
}

void renderFrameLoop(Renderer &renderer, GLFWwindow *window)
{
	bool needRecompute = true;
 
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawPixels(SCR_WIDTH, SCR_HEIGHT, GL_RGB, GL_FLOAT, &renderer.OutputImage[0]);

		computeRayTracing(renderer);
		flipImageVertically(renderer.OutputImage, SCR_WIDTH, SCR_HEIGHT);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS
			|| glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
}
