#include "Image.h"
#include <stdio.h>

int SPng::DrawJPGImage(unsigned char* pBuffer)
{
	int iImage = reinterpret_cast<int>(pBuffer);

	return iImage;
}

void SPng::RemoveAlphaChanel() 
{
	printf("Remove alpha channel\n");
}