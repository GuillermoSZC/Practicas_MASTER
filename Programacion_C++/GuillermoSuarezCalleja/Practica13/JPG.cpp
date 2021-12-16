#include"JPG.h"
#include<iostream>

SJpg::SJpg()
{
	m_oImage = nullptr;
	cType = "jpg";
}

SJpg::~SJpg()
{
	printf("Objeto de la clase JPG borrado.\n"); 
}