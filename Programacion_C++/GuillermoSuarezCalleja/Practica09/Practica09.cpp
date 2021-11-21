#include <iostream>
#include "TList.h"

int main()
{
	TList* nodo = new TList();

	nodo->mPush("hello");
	nodo->mPush("bye");
	nodo->mPush("123");
	nodo->mPush("234");
	nodo->mPush("456");
	
	nodo->mShowList();

	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;

	std::cout << "\n..First element of list..\n" << nodo->mFirst() << std::endl;

	std::cout << "\n..Next element of list..\n" << nodo->mNext() << std::endl;

	std::cout << "\n..First element of list erased..\n" << nodo->mPop() << std::endl;

	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;

	std::cout << "\n..Reset list..\n";
	nodo->mReset();


	delete nodo;
	nodo = nullptr;

	return 0;
}