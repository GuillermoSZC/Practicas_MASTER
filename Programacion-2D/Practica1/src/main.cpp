#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "vec2.h"

int main() {
	double xpos, ypos;
	int width = 1280, height = 960;
	float lado = 50.f;

	GLFWwindow* window;

	glfwInit();
	

	glfwGetTime();

	if (!glfwInit())
	{
		printf("error init");
	}

	window = glfwCreateWindow(width, height, "P1", NULL, NULL);
	if (!window)
	{
		printf("error window");
	}

	while (!glfwWindowShouldClose(window))
	{
		lgfx_setup2d(width, height);
		lgfx_clearcolorbuffer(1.f, 1.f, 1.f);

		lgfx_setcolor(0.3f, 0.7f, 0.85f, 1.f);
		lgfx_drawrect((width / 2) - lado / 2, (height / 2) - lado / 2, lado, lado);
		
		glfwGetCursorPos(window, &xpos, &ypos);
		lgfx_setcolor(0.3f, 0.7f, 0.85f, 1.f);
		lgfx_drawrect(xpos-lado/2, ypos-lado/2, lado, lado);

		glfwMakeContextCurrent(window);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
	glfwTerminate();

  return 0;
}

