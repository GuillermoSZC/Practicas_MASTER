#include"Functions.h"
#include<iostream>

bool mCadena(const char* _indice)
{
	const char* sTabla[]{ "Hello", "Bye" };
	int sizeArray = sizeof(sTabla) / sizeof(sTabla[0]);

	bool val = false;

	for (int i = 0; i < sizeArray; ++i)
	{
		if (strcmp(*(sTabla + i), _indice) == 0)
		{
			char* auxRev(nullptr);
			mReverseString(*(sTabla + i), auxRev);

			std::cout << "Reversed " << *(sTabla + i) << " on: " << auxRev << std::endl;

			// borro la variable auxiliar que referencia en memoria al new de mReverseString()
			delete auxRev; 
			auxRev = nullptr; 

			val = true;
		}
	}

	return val;
}

void mReverseString(const char* _indice, char*& ret_)
{
	int iSize = strlen(_indice);
	ret_ = new char[iSize + 1];

	ret_[iSize] = '\0';

	int i = 0, j = iSize - 1;

	while (i < iSize)
	{
		*(ret_ + i) = *(_indice + j);
		++i; --j;
	}
}