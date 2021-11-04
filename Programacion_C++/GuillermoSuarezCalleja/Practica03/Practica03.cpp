#include<iostream>
#include<string>

bool mCadena(std::string);
std::string mReverseString(std::string);

int main() 
{
	std::string indice("Hello");

	if (mCadena(indice))
	{
		std::cout << "The word " << indice << " is inside of string table." << std::endl;
	}
	else
	{
		std::cout << "The word " << indice << " isn't inside of string table." << std::endl;
	}
	
}

bool mCadena(std::string _indice) 
{
	std::string sTabla[] = { "Hello", "Bye" };
	std::string* ptrTabla = reinterpret_cast<std::string*>(sTabla);

	int sizeArray = sizeof(sTabla) / sizeof(sTabla[0]);
	bool val = false;

	for (int i = 0; i < sizeArray; ++i)
	{
		// std::cout << *(ptrTabla + i) << std::endl;
		if (*(ptrTabla + i) == _indice) // si la posicion i de la tabla es == al parametro de mCadena..
		{
			std::cout << "Reverse string: " << mReverseString(*(ptrTabla + i)) << std::endl;
			val = true;
		} 
	}

	return val;
}

std::string mReverseString(std::string _indice)
{
	std::string* ptr = &_indice;
	std::string rev = std::string(_indice.rbegin(), _indice.rend()); // Reverse the string: _indice

	*ptr = rev;

	return _indice;
}