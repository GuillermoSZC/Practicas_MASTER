#include <iostream>
#include "FileManager.h"

int main() 
{
	char cBuffer[100];
	char cText[]("Hello world, this is an example file..");
	unsigned int iSize = sizeof(cText) / sizeof(cText[0]);
	const char* cfName("Practica5.txt");
	void* vFile(nullptr);
	bool bVal(true);
	int iOpt(INT_MIN);
	char* cAux(nullptr);

	do 
	{
		std::cout << "What would you like to do? 0 - 1" << std::endl;
		std::cin >> iOpt;
		if (iOpt == 0 || iOpt == 1)
		{
			bVal = false;
		}
	} while (bVal);

	if (iOpt == 0) // lectura
	{
		vFile = FileManager::mOpenFile(cfName, "r"); // fichero abierto para lectura
		std::cout << "Number of chars read: " << FileManager::mReadFile(vFile, cBuffer, cAux) << std::endl;
		delete cAux;
		cAux = nullptr;
	}
	else if (iOpt == 1) // escritura
	{
		vFile = FileManager::mOpenFile(cfName, "w"); // fichero abierto para escritura
		std::cout << "Characters that was written: " << FileManager::mWriteFile(vFile, cText, iSize) << std::endl;
	}

	return 0;
}

