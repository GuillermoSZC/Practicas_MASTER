#include <iostream>
#include "TList.h"

int main()
{
	TList <int> obj;
	TList <const char*> obj2;
	TList <char> obj3;

	int opt;
	std::cout << "1-[INT] \n2-[CONST CHAR*]\n3-[CHAR]\n";
	std::cin >> opt;
	switch (opt)
	{
	case 1: // probar si se pueden introducir int
		obj.mPush(1);
		obj.mPush(2);
		obj.mPush(3);
		obj.mPush(4);

		obj.mShowList();
		std::cout << "\nSize of list: \n" << obj.mSize() << std::endl;

		std::cout << "\n..First element of list..\n" << obj.mFirst() << std::endl;
		std::cout << "\n..Next element of list..\n" << obj.mNext() << std::endl;

		std::cout << "\n..First element of list erased..\n" << obj.mPop() << std::endl;

		std::cout << "\nSize of list: \n" << obj.mSize() << std::endl;

		std::cout << "\n..Reset list..\n";
		obj.mReset();
		break;

	case 2: // Probar si se pueden introducir cadenas const char*
		obj2.mPush("hello");
		obj2.mPush("bye");
		obj2.mPush("asd");
		obj2.mPush("dsf");

		obj2.mShowList();
		std::cout << "\nSize of list: \n" << obj2.mSize() << std::endl;

		std::cout << "\n..First element of list..\n" << obj2.mFirst() << std::endl;
		std::cout << "\n..Next element of list..\n" << obj2.mNext() << std::endl;

		std::cout << "\n..First element of list erased..\n" << obj2.mPop() << std::endl;

		std::cout << "\nSize of list: \n" << obj2.mSize() << std::endl;

		std::cout << "\n..Reset list..\n";
		obj2.mReset();
		break;

	case 3: // probar si se pueden introducir char
		obj3.mPush('a');
		obj3.mPush('b');
		obj3.mPush('c');
		obj3.mPush('d');

		obj3.mShowList();
		std::cout << "\nSize of list: \n" << obj3.mSize() << std::endl;

		std::cout << "\n..First element of list..\n" << obj3.mFirst() << std::endl;
		std::cout << "\n..Next element of list..\n" << obj3.mNext() << std::endl;

		std::cout << "\n..First element of list erased..\n" << obj3.mPop() << std::endl;

		std::cout << "\nSize of list: \n" << obj3.mSize() << std::endl;

		std::cout << "\n..Reset list..\n";
		obj3.mReset();
		break;

	default:
		break;
	}
	

	return 0;
}

