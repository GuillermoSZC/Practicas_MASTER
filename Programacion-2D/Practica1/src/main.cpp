#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include "vec2.h"

int main() {
  

	vec2 vecSuma = suma(vec2(1, 1), vec2(3, 4));
  std::cout <<"Suma: vec2(" << vecSuma.x << "," << vecSuma.y << ")" << std::endl;
	
	vec2 vecResta = resta(vec2(5, 7), vec2(3, 5));
	std::cout << "Resta: vec2(" << vecResta.x << "," << vecResta.y << ")" << std::endl;
	
	vec2 vecProducto = producto(vec2(2, 4), vec2(3, 4));
	std::cout << "Producto: vec2(" << vecProducto.x << "," << vecProducto.y << ")" << std::endl;

	vec2 vecDivision = division(vec2(20, 35), vec2(2, 7));
	std::cout << "Division: vec2(" << vecDivision.x << "," << vecDivision.y << ")" << std::endl;

	float vecAbsoluto = vAbsoluto(vec2(3, 4));
	std::cout << "Valor absoluto: " << vecAbsoluto << std::endl;

	float nm = normal(vec2(3, 3));
	std::cout << "Normal: " << nm << std::endl;

	float esc = pEscalar(vec2(3, 0), vec2(5, 5));
	std::cout << "Producto escalar: " << esc << std::endl;

  return 0;
}