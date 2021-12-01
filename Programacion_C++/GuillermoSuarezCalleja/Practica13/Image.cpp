#include "Image.h"
#include<iostream>


void SPng::mDeleteAlphaChannel(SImage** tabla, int size)
{
	SImage* pTabla = nullptr;
	SPng* pPng = nullptr;

	for (int i = 0; i < size; ++i)
	{
		pTabla = *(tabla + i);
		if (strcmp(tabla[i]->bType, "png") == 0)
		{
			pPng = static_cast<SPng*>(pTabla);
			pPng->iAlpha = 0;
			std::cout << "Alpha channel borrado." << std::endl;
		}
		else
		{
			std::cout << pTabla->bType<< std::endl;
		}
	}
	printf("\n");
}