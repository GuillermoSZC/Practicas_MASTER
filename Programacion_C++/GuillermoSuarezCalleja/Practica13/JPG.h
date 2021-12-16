#include "Image.h"


class SJpg : public SImage
{
private:
	SImage* m_oImage;
public:
	SJpg();
	~SJpg() override;
	int mDrawJPGImage(unsigned char* pBuffer);
};
