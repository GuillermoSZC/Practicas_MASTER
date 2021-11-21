#include <iostream>
#include "TList.h"
#include "FileManager.h"

int main()
{
	TList* nodo = new TList();
	char* aux = nullptr;
	const char* cNameOfFile = "FileManager.txt";

	nodo = nodo->mPushNumsOfFile(cNameOfFile, aux);

	std::cout << "\nList content:" << std::endl;
	nodo->mShowList();

	std::cout << "\n..Reset list..\n";
	nodo->mReset();

	delete aux;
	aux = nullptr;
	delete nodo;
	nodo = nullptr;

	return 0;
}