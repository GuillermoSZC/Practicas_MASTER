#include"TList.h"
#include<iostream>

int TList::mPush(const char* cValue)
{
	TList::Nodo* nNode = new TList::Nodo(cValue);

	nNode->next = nullptr;
	nNode->prev = tail;

	if (!head)
	{
		head = nNode;
	}
	else if(tail != nullptr)
	{
		tail->next = nNode;
	}
	tail = nNode;

	nNode->id = iSize;

	++iSize;
	return head->id;
}

int TList::mSize() const
{
	return iSize;
}

const char* TList::mFirst() const
{
	return head->cData;
}

const char* TList::mNext() const
{
	TList::Nodo* tmp = head;
	tmp = head->next;

	return tmp->cData;
}

const char* TList::mPop()
{
	const char* cString = nullptr;
	if (head)
	{
		cString = head->cData;
		--iSize;
		TList::Nodo* temp = head;

		head = head->next;
		delete temp;
	}

	return cString;
}

TList TList::GetReverseList(TList lista)
{
	TList newList;

	// si el head de la nueva lista es NULL le paso el final de la lista que paso por parametro
	if (!newList.head)
	{
		newList.mPush(lista.tail->cData);
		newList.head->next = nullptr;
	}
	// comparo los tamaños de cada lista para ir haciendo push a la nueva lista
	// empezando por el final (tail e iterando con el prev) de la lista que paso por parametro
	while (newList.iSize != lista.iSize) 
	{
		newList.mPush(lista.tail->prev->cData);
		lista.tail = lista.tail->prev;
	}

	return newList;
}

void TList::mShowList() const
{
	TList aux;
	aux.head = head;
	printf("\n");
	while (aux.head != NULL)
	{
		std::cout << "Element " << aux.head->id << ": " << aux.head->cData << std::endl;
		aux.head = aux.head->next;
	}
}

void TList::mReset()
{
	TList::Nodo* tmp = nullptr;
	while (head)
	{
		tmp = head;
		std::cout << "Element " << head->cData << " erased.\n";
		head = head->next;
		delete tmp;
	}
}