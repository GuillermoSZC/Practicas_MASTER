#define LITE_GFX_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "vec2.h"
#include <string>
#include "stb_image.h"



ltex_t* loadTexture(const char* _filename);

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

	ltex_t* wall = loadTexture("C:/Users/Soker/Documents/GitHub/Practicas_MASTER/Programacion-2D/Practica2/data/wall.jpg");
	ltex_t* fire = loadTexture("data/fire.png");
	ltex_t* grille = loadTexture("grille.png");
	ltex_t* light = loadTexture("light.png");

	GLFWwindow* window;

	glfwInit();
	if (!glfwInit())
	{
		printf("error init");
	}

	window = glfwCreateWindow(width, height, "P1", NULL, NULL);
	if (!window)
	{
		printf("error window");
	}
	glfwMakeContextCurrent(window);
	lgfx_setup2d(width, height);

	while (!glfwWindowShouldClose(window))
	{
		glfwGetTime();
		delta = glfwGetTime();

		lgfx_clearcolorbuffer(1.f, 1.f, 1.f);

		lgfx_setcolor(0.f, 0.f, 0.f, 1.f);
		lgfx_drawrect(100, 100, 50, 50);
		lgfx_setcolor(1.f, 1.f, 1.f, 1.f);


		lgfx_setblend(BLEND_SOLID);
		ltex_drawrotsized(wall, 0, 0, 0, 0, 0, width, height, 0, 0, width / wall->width, height / wall->height);


		glfwGetCursorPos(window, &xposMouse, &yposMouse);
		cursorPosition.x = xposMouse;
		cursorPosition.y = yposMouse;



		textDist = center.distance(cursorPosition);

		// std::string title = "Distance: "
		// 	+ std::to_string(textDist)
		// 	/*+ ", Angle: "
		// 	+ std::to_string(textAngle)*/;
		// 
		// glfwSetWindowTitle(window, title.c_str());

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

ltex_t* loadTexture(const char* _filename)
{
	int* x = new int;
	int* y = new int;

	unsigned char* buffer = stbi_load(_filename, x, y, nullptr, 4);
	ltex_t* tex = ltex_alloc(*x, *y, 1);
	ltex_setpixels(tex, buffer);
	stbi_image_free(buffer);

	return tex;
}
