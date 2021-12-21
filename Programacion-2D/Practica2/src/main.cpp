#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "vec2.h"
#include <string>
#include "stb_image.h"

int main() {
	double xpos, ypos;
	double xposMouse, yposMouse;
	int width = 1280, height = 960;
	float lado = 50.f;
	float angle = 0.f;
	float fDistance = 100.f;
	float delta;
	float textDist, textAngle;
	std::string cad;
	vec2 cursorPosition;
	vec2 center((float)(width / 2.f), (float)(height / 2.f));

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
		
		delta = glfwGetTime();

		lgfx_setup2d(width, height);
		lgfx_clearcolorbuffer(0.f, 0.f, 0.f);
		

		glfwGetCursorPos(window, &xposMouse, &yposMouse);
		cursorPosition.x = xposMouse;
		cursorPosition.y = yposMouse;



		textDist = center.distance(cursorPosition);

		std::string title = "Distance: "
			+ std::to_string(textDist)
			/*+ ", Angle: "
			+ std::to_string(textAngle)*/;

		glfwSetWindowTitle(window, title.c_str());

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
ltex_t* loadTexture(const char*);
ltex_t* loadTexture(const char* filename, int width, int height)
{
	int channels = 0;
	float* image = stbi_loadf(filename, &width, &height, &channels, STBI_rgb_alpha);
	return image;
}
