#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "Vec2.h"

using namespace std;

int main() {
	float v1[2] = { 2.f,4.f };
	float v2[2] = { 1.f,2.f };
	
	Vec2* obj = new Vec2(v1, v2);

	std::cout << "Sum vector:\n vec - { ";
	for (int i = 0; i < 2; ++i)
	{
		std::cout << obj->suma(v1, v2)[i] << " ";
	}
	std::cout << "}" << std::endl;

	std::cout << "Minum vector:\n vec - { ";
	for (int i = 0; i < 2; ++i)
	{
		std::cout << obj->resta(v1, v2)[i] << " ";
	}
	std::cout << "}" << std::endl;

	std::cout << "Product vector:\n vec - { ";
	for (int i = 0; i < 2; ++i)
	{
		std::cout << obj->producto(v1, v2)[i] << " ";
	}
	std::cout << "}" << std::endl;

	std::cout << "Div vector:\n vec - { ";
	for (int i = 0; i < 2; ++i)
	{
		std::cout << obj->division(v1, v2)[i] << " ";
	}
	std::cout << "}" << std::endl;

	delete obj;

    return 0;
}