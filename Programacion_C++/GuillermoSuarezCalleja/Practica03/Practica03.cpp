#include<iostream>

bool mCadena(const char*);
const char* mReverseString(const char*);

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

const char* mReverseString(const char* _indice)
{
	// std::cout << *(_indice + 0) << std::endl;
	// std::cout << *(_indice + 1) << std::endl;
	// std::cout << *(_indice + 2) << std::endl;
	// std::cout << *(_indice + 3) << std::endl;
	// std::cout << *(_indice + 4) << std::endl;
	
	int iSize = strlen(_indice);
	char* aux = const_cast<char*>(_indice);
	int i = 0;
	int j = iSize;

	while (*(_indice + i) != '\0')
	{
		// std::cout << *(_indice + i) << std::endl;
		// std::cout << *(_indice + j) << std::endl;
		*aux = const_cast<const char*>(*(_indice + j));
		++i;
		--j;
	}
	// std::cout << aux << std::endl;
	// std::cout << _indice << std::endl;

	return aux;
}