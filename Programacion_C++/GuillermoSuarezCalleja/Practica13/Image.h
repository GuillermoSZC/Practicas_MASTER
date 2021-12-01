#pragma once
#include <stdio.h>

struct SImage
{
	int m_iResolutionX, m_iResolutionY;
	int m_iColorDepth;
	const char* bType;
	int iAlpha;

	SImage() 
	{
		m_iResolutionX = 1080;
		m_iResolutionY = 720;
		m_iColorDepth = 255;
		bType = "image";
		iAlpha = 255;
	}
	~SImage() { printf("Objeto de la clase SImage borrado.\n"); }
	int DrawRGBImage(unsigned char* pBuffer);
};

struct SJpg : public SImage
{
	SImage* m_oImage;
	SJpg()
	{
		m_oImage = nullptr;
		bType = "jpg";
	}
	~SJpg() { printf("Objeto de la clase JPG borrado.\n"); }
	int mDrawJPGImage(unsigned char* pBuffer);
};

struct SPng : public SImage
{
	SImage* m_oImage;
	SPng()
	{
		m_oImage = nullptr;
		bType = "png";
	}
	~SPng() { printf("Objeto de la clase PNG borrado.\n"); }
	int mDrawPNGImage(unsigned char* pBuffer);
	void mDeleteAlphaChannel(SImage**, int);
};