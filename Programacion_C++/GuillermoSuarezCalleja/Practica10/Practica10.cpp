#include <iostream>
#include "TList.h"
#include "FileManager.h"

int main()
{
	TList* nodo = nullptr;

	const char* dato;
	dato = "hello";
	std::cout << "Element added.\nList Size: " << nodo->mPush(nodo, dato) << std::endl;

	dato = "world";
	std::cout << "Element added.\nList Size: " << nodo->mPush(nodo, dato) << std::endl;

	dato = "bye";
	std::cout << "Element added.\nList Size: " << nodo->mPush(nodo, dato) << std::endl;

	dato = "asd";
	std::cout << "Element added.\nList Size: " << nodo->mPush(nodo, dato) << std::endl;

	dato = "dfg";
	std::cout << "Element added.\nList Size: " << nodo->mPush(nodo, dato) << std::endl;
	
	std::cout << "\n..First element of list..\n" << nodo->mFirst(nodo) << std::endl;

	std::cout << "\n..Next element of list..\n" << nodo->mNext(nodo) << std::endl;

	std::cout << "\n..First element of list erased..\n" << nodo->mPop(nodo) << std::endl;

	std::cout << "\n..Reset list..\n";
	nodo->mReset(nodo);

	
	return 0;
}