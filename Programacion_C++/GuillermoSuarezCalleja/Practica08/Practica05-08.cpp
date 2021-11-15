#include <iostream>
#include "FileManager.h"

int main() 
{
	FileManager* obj = new FileManager();

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

	if (iOpt == 0)
	{
		vFile = obj->mOpenFile(cfName, "r");
		std::cout << "Number of chars read: " << obj->mReadFile(vFile, cBuffer, cAux) << std::endl;
		delete cAux;
		cAux = nullptr;
	}
	else if (iOpt == 1)
	{
		vFile = obj->mOpenFile(cfName, "w");
		std::cout << "Characters that was written: " << obj->mWriteFile(vFile, cText, iSize) << std::endl;
	}

	delete obj;
	obj = nullptr;

	return 0;
}