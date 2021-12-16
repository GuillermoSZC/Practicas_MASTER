#include "Image.h"

class SPng : public SImage
{
private:
	SImage* m_oImage;
public:
	SPng();
	~SPng() override;
	int mDrawPNGImage(unsigned char* pBuffer);
	void mDeleteAlphaChannel(SImage**, int);
};