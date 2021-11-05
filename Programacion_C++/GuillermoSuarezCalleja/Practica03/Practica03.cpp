#include<iostream>

bool mCadena(const char*);
void mReverseString(const char*, char*& ret_);

int main() 
{
	char indice[] = "Hello";

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
		if (strcmp(*(sTabla + i), _indice) == 0)
		{
			char* asd(nullptr);
			mReverseString(*(sTabla + i), asd);
			std::cout << "Reversed " << *(sTabla + i) << " on: " << asd << std::endl;
			delete asd;
			asd = nullptr;
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