#include <iostream>
#include "FileManager.h"

int main()
{
	const char* cfName("Practica6.txt");
	char cText[]("Hello hello, hHello, helloa ahello Hellob 100,50 25,50,25 25,25 55 45 Hello");
	char cadena[]("Hello");
	unsigned int iSize = sizeof(cText) / sizeof(cText[0]);
	int iOpt(INT_MIN);
	void* vFile(nullptr);
	bool bVal(true);

	do
	{
		std::cout << "What would you like to do?\n"
			"0. Read num chars\n"
			"1. Write\n"
			"2. Count Strings\n"
			"3. Sum of file numbers\n" << std::endl;
		std::cin >> iOpt;
		if (iOpt == 0 || iOpt == 1 || iOpt == 2 || iOpt == 3)
		{
			bVal = false;
		}
	} while (bVal);

	switch (iOpt)
	{
	case 0:
		vFile = FileManager::mOpenFile(cfName, "r");
		std::cout << "Number of characters read: " << FileManager::mReadFile(vFile) << std::endl;
		break;
	case 1:
		vFile = FileManager::mOpenFile(cfName, "w");
		std::cout << "Characters that was written: " << FileManager::mWriteFile(vFile, cText, iSize) << std::endl;
		break;
	case 2:
		vFile = FileManager::mOpenFile(cfName, "r");
		std::cout << "Number of '" << cadena << "'  read: " << FileManager::mNumOfStrings(vFile, cadena) << std::endl;
		break;
	case 3:
		vFile = FileManager::mOpenFile(cfName, "r");
		std::cout << "Sum of file numbers: " << FileManager::mSumaNumeros(vFile) << std::endl;
		break;
	default:
		std::cout << "Error" << std::endl;
	}

	return 0;
}