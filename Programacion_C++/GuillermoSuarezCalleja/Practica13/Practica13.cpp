#include <iostream>
#include "Image.h"


int main()
{
	const char* type = "hola";
	printf("%s\n",type);

	SImage* mTabla[5];

	SImage* obj = mTabla[0];
	SPng* oPng = static_cast<SPng*>(obj);
	// SPng* oJpg = static_cast<SJpg*>(obj);

	oPng->RemoveAlphaChanel();
	obj = mTabla[1];
	oPng = static_cast<SPng*>(obj);
	oPng->RemoveAlphaChanel();
	obj = mTabla[2];
	oPng = static_cast<SPng*>(obj);
	oPng->RemoveAlphaChanel();
	obj = mTabla[3];
	oPng = static_cast<SPng*>(obj);
	oPng->RemoveAlphaChanel();
	obj = mTabla[4];
	oPng = static_cast<SPng*>(obj);
	oPng->RemoveAlphaChanel();



	return 0;
}