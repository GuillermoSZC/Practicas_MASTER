#include"TList.h"
#include<iostream>

int TList::mPush(TList*& list, const char* cValue)
{
	TList* nNode = new TList();
	nNode->cData = cValue;

	TList* aux1 = list;
	TList* aux2 = nullptr;

	while ((aux1 != nullptr))
	{
		aux2 = aux1;
		aux1 = aux1->next;
	}

	if (list == aux1)
	{
		list = nNode;
	}
	else
	{
		aux2->next = nNode;
	}
	nNode->next = aux1;
	list->iSize++;

	return list->iSize;
}

const char* TList::mFirst(TList*& head)
{
	return head->cData;
}

const char* TList::mNext(TList*& head)
{
	TList* tmp = head;
	tmp = head->next;

	return tmp->cData;
}

const char* TList::mPop(TList*& head)
{
	const char* cString = nullptr;
	if (head)
	{
		cString = head->cData;
		TList* temp = head;
		head = head->next;
		delete temp;
	}

	return cString;
}

void TList::mReset(TList*& head)
{
	TList* tmp = nullptr;
	while (head)
	{
		tmp = head;
		std::cout << "Element " << head->cData << " erased.\n";
		head = head->next;
		delete tmp;
	}
}