#include<iostream>
#include"TList.h"

int main()
{
	Tool::TList* nodo = new Tool::TList();

	nodo->Push("Hello");
	nodo->Push("bye");
	nodo->Push("123");
	nodo->Push("345");
	nodo->ShowList();

	return 0;
}