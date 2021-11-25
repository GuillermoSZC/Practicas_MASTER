#include <iostream>
#include "TList.h"

int main()
{
	TList* nodo = new TList();

	TList* nodo2 = new TList(nodo);

	nodo->mPush("hello");
	nodo->mPush("bye");
	nodo->mPush("123");
	nodo->mPush("234");
	nodo->mPush("456");
	
	nodo->mShowList();

	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;

	std::cout << "\n..First element of list..\n" << nodo2->mFirst() << std::endl;

	std::cout << "\n..Next element of list..\n" << nodo->mNext() << std::endl;

	std::cout << "\n..First element of list erased..\n" << nodo2->mPop() << std::endl;

	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;

	std::cout << "\n..Reset list..\n";
	nodo->mReset();


	delete nodo;
	nodo = nullptr;

	return 0;
}