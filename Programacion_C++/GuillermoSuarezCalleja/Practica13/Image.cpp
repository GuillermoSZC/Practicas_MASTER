#include "Image.h"

SImage::SImage()
{
	m_iResolutionX = 1080;
	m_iResolutionY = 720;
	m_iColorDepth = 255;
	cType = "image";
	uiAlpha = 255;
}

SImage::~SImage() 
{
	printf("Objeto de la clase SImage borrado.\n"); 
}

void SImage::setAlpha(unsigned int _uiAlpha)
{
	uiAlpha = _uiAlpha;
}

void SImage::setType(const char* _cType)
{
	cType = _cType;
}