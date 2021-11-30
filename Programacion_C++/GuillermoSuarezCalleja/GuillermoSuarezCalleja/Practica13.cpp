#include<iostream>
#include"Image.h"


int main()
{
	SImage* tabla[4];

	tabla[0] = new SJpg();
	tabla[1] = new SPng();
	tabla[2] = new SPng();
	tabla[3] = new SJpg();

	int size = sizeof(tabla) / 4;

	SPng* image = nullptr;

	image->mDeleteAlphaChannel(tabla, size);
	
	delete[] tabla;

	return 0;
}