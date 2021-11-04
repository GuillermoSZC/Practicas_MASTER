#include "FileManager.h"
#include <iostream>

using namespace std;

int main() 
{
	char name[] = "example.txt";
	char* ptrName = name;
	int iOpt = 0;
	std::cout << "Quieres abrir para lectura o escritura? 0-1" << std::endl;
	std::cin >> iOpt;

	if (iOpt == 0)
	{
		mOpenFile(ptrName, iOpt);
	}
	else if (iOpt == 1)
	{
		mOpenFile(ptrName, iOpt);
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}
	
	return 0;
}