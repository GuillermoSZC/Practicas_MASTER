#include"TList.h"
#include<iostream>

int TList::mPush(const char* cValue)
{
	TList::Nodo* nNode = new TList::Nodo(cValue);

	nNode->next = nullptr;
	nNode->prev = tail;

	if (!head) // si el head está vacio le asigno el nodo
	{
		head = nNode;
	}
	else
	{
		tail->next = nNode;
	}
	tail = nNode;

	nNode->id = iSize; // se le asigna un id al nodo dependiendo del tamaño del mismo

	++iSize;
	return head->id; // devuelve el identificador que se le ha asignado al nodo
} // metodo para insertar nodos a la lista

int TList::mSize()
{
	return iSize;
} // metodo para devolver el tamaño de la lista

const char* TList::mFirst()
{
	return head->cData;
} // metodo para mostrar el primer nodo de la lista

const char* TList::mNext()
{
	TList::Nodo* tmp = head;
	tmp = head->next;

	return tmp->cData;
} // metodo para mostrar el segundo nodo de la lista

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
} // metodo para borrar el primer nodo de la lista

void TList::mShowList()
{
	TList aux;
	aux.head = head;

	while (aux.head != NULL)
	{
		std::cout << "Element " << aux.head->id << ": " << aux.head->cData << std::endl;
		aux.head = aux.head->next;
	}
} // metodo para mostrar todos los nodos de la lista desde head en adelante

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
} // metodo para borrar todos los nodos de la lista 