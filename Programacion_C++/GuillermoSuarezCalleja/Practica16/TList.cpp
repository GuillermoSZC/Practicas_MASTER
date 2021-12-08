#include"TList.h"
#include<iostream>
#include "Enemy.h"

int TList::mPush(Enemy* cValue)
{
	TList::Nodo* nNode = new TList::Nodo(cValue);

	nNode->next = nullptr;
	nNode->prev = tail;

	if (!head)
	{
		head = nNode;
	}
	else
	{
		tail->next = nNode;
	}
	tail = nNode;

	nNode->id = iSize;

	++iSize;
	return head->id;
}

int TList::mSize()
{
	return iSize;
}

Enemy* TList::mFirst() const
{
	return head->cData;
}

Enemy* TList::mNext()
{
	TList::Nodo* tmp = head;
	tmp = head->next;

	return tmp->cData;
}

Enemy* TList::mPop()
{
	Enemy* cString = nullptr;
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

void TList::mShowList()
{
	TList aux;
	aux.head = head;
	std::cout << "\n";
	while (aux.head != NULL)
	{
		std::cout << "Elemento " << aux.head->id << ": " << aux.head->cData->vmGetName();
		std::cout << "\nTipo: " << aux.head->cData->vmGetType();
		std::cout << "\nEstadisticas: ";
		aux.head->cData->vmGetStats();
		aux.head = aux.head->next;
	}
}

void TList::mReset()
{
	TList::Nodo* tmp = nullptr;
	std::cout << "\n";
	while (head)
	{
		tmp = head;
		std::cout << "Elemento " << head->cData->vmGetName() << " borrado de la lista.\n";
		head = head->next;
		delete tmp;
	}
}