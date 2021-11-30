#pragma once

struct SImage
{
	int m_iResolutionX, m_iResolutionY;
	int m_iColorDepth;
	int DrawRGBImage(unsigned char* pBuffer);

};

struct SJpg : public SImage
{
	const char* name = "jpg";
	// CCodecJPG m_oCodec;
	int DrawJPGImage(unsigned char* pBuffer);
	void RemoveAlphaChanel();
};

struct SPng : public SImage
{
	const char* name;
	// CCodecPNG m_oCodec;
	int DrawJPGImage(unsigned char* pBuffer);
	void RemoveAlphaChanel();
};