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
		
		// std::cout << *(ptrTabla + i) << std::endl;
		if (*(sTabla + i) == _indice) // si la posicion i de la tabla es == al parametro de mCadena..
		{
			std::cout << "Reversed " << *(sTabla + i) << " on: " << mReverseString(_indice) << std::endl;
			val = true;
		} 
	}

	return val;
}

char* mReverseString(const char* _indice)
{
	int iSize = strlen(_indice);
	char* indiceRev_ = new char[iSize + 1];
	strcpy(indiceRev_, _indice);

	for (int i = 0, j = iSize - 1; i < j; ++i, --j)
	{
		std::swap(*(indiceRev_ + i), *(indiceRev_ +j));
	}
	return indiceRev_;
}