#pragma once
#include <stdio.h>

class SImage
{
protected:
	const char* cType;
	unsigned int uiAlpha;

private:
	unsigned int m_iResolutionX, m_iResolutionY;
	unsigned int m_iColorDepth;
	
public:
	SImage();
	virtual ~SImage();
	int DrawRGBImage(unsigned char* pBuffer);

	void setType(const char*);
	void setAlpha(unsigned int);

	const char* getType() const { return cType; }
	unsigned int getAlpha() const { return uiAlpha; }
};