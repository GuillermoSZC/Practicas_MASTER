#include"PNG.h"
#include<iostream>

SPng::SPng()
{
	m_oImage = nullptr;
	cType = "png";
}

SPng::~SPng()
{
	printf("Objeto de la clase PNG borrado.\n");
}

void SPng::mDeleteAlphaChannel(SImage** tabla, int size) 
{
	SImage* pTabla = nullptr;
	SPng* pPng = nullptr;

	for (int i = 0; i < size; ++i)
	{
		pTabla = *(tabla + i);
		if (strcmp(tabla[i]->getType(), "png") == 0)
		{
			pPng = static_cast<SPng*>(pTabla);
			pPng->setAlpha(0);

			std::cout << "[PNG] Alpha channel borrado." << std::endl;
		}
		else
		{
			std::cout << pTabla->getType() << std::endl;
		}
	}
	printf("\n");
}