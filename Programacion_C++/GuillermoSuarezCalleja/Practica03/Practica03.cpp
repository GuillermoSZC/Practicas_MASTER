#include<iostream>

bool mCadena(const char*);
char* mReverseString(const char*);

int main() 
{
	const char* indice("Hello");

	if (mCadena(indice))
	{
		std::cout << "The word " << indice << " is inside of string table." << std::endl;
	}
	else
	{
		std::cout << "The word " << indice << " isn't inside of string table." << std::endl;
	}
	
}

bool mCadena(const char* _indice) 
{
	const char* sTabla[]{ "Hello", "Bye" };
	int sizeArray = sizeof(sTabla) / sizeof(sTabla[0]);

	bool val = false;

	for (int i = 0; i < sizeArray; ++i)
	{
		if (*(sTabla + i) == _indice)
		{
			std::cout << "Reversed " << *(sTabla + i) << " on: " << mReverseString(*(sTabla + i)) << std::endl;
			val = true;
		} 
	}

	return val;
}

char* mReverseString(const char* _indice)
{
	int iSize = strlen(_indice);
	char* indiceRev_ = new char[iSize];

	indiceRev_[iSize] = '\0';

	int i = 0, j = iSize - 1;

	while (i < iSize)
	{
		*(indiceRev_ + i) = *(_indice + j);
		++i; --j;
	}

	return indiceRev_;
}