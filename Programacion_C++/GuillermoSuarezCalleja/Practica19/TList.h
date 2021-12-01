#pragma once
#include<iostream>

template<typename T1>
class  TList
{
private:
	
	struct Nodo 
	{
		
		T1 cData;
		Nodo* next;
		Nodo* prev;
		int id;
		Nodo(T1 value) 
		{
			id = 0;
			cData = value;
			next = nullptr;
			prev = nullptr;
		}
	};

	int iSize;
	TList::Nodo* head;
	TList::Nodo* tail;
	
public:
	TList()
	{
		iSize = 0;
		head = nullptr;
		tail = nullptr;
	};


	int mSize()
	{
		return iSize;
	}


	int mPush(T1 cValue)
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


	T1 mFirst()
	{
		return head->cData;
	}


	T1 mNext()
	{
		TList::Nodo* tmp = head;
		tmp = head->next;

		return tmp->cData;
	}

	T1 mPop()
	{
		T1 cString = NULL;
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


	void mShowList()
	{
		TList aux;
		aux.head = head;

		while (aux.head != NULL)
		{
			std::cout << "Element " << aux.head->id << ": " << aux.head->cData << std::endl;
			aux.head = aux.head->next;
		}
	}


	void mReset()
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
};