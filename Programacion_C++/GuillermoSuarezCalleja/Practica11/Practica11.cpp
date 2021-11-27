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
	
	TList nodo2 = TList::GetReverseList(nodo);

	std::cout << "\n..First element of list.. NODO 2\n" << nodo2.mFirst() << std::endl;

	nodo2.mShowList();
	
	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;

	std::cout << "\n..First element of list..\n" << nodo->mFirst() << std::endl;

	std::cout << "\n..Next element of list..\n" << nodo->mNext() << std::endl;

	std::cout << "\n..First element of list erased..\n" << nodo->mPop() << std::endl;

	std::cout << "\nSize of list: \n" << nodo->mSize() << std::endl;



	std::cout << "\n..Reset list..\n";
	nodo->mReset();

	std::cout << "\n..Reset list NODO2..\n";
	nodo2.mReset();

	delete nodo;
	nodo = nullptr;

	return 0;
}