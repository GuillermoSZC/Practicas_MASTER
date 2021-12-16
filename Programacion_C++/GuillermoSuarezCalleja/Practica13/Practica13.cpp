#include <iostream>
#include "Image.h"
#include "JPG.h"
#include "PNG.h"

int main()
{
	SImage* tabla[4];

	tabla[0] = new SJpg();
	tabla[1] = new SPng();
	tabla[2] = new SPng();
	tabla[3] = new SJpg();

	int size = sizeof(tabla) / 4;

	SPng* pngImg = nullptr;

	pngImg->mDeleteAlphaChannel(tabla, size);

	for (int i = 0; i < size; ++i)
	{
		delete tabla[i];
	}

	return 0;
}