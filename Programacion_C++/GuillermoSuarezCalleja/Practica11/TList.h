#pragma once

class  TList
{
private:
	struct Nodo
	{
		const char* cData;
		Nodo* next;
		Nodo* prev;
		int id;

		Nodo(const char* value)
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
	TList::Nodo* current;

public:
	TList()
	{
		iSize = 0;
		head = nullptr;
		tail = nullptr;
		current = nullptr;
	};

	TList(TList*& list)
	{
		iSize = 0;
		head = nullptr;
		tail = nullptr;
		TList::Nodo* nNode = nullptr;
		// si el head de la lista no es NULL, lo igualo a NULL
		if (!list->head)
		{
			head = nullptr;
		}
		else 
		{
			// si está vacio inserto a la lista el nodo correspondiente y despues apunto 
			// al siguiente nodo de la lista que paso por parametro
			mPush(list->head->cData);
			nNode = list->head->next;
		}
		// mientras el nodo no sea NULL voy haciendo el push correspondiente para 
		// hacer la copia de la lista 
		while (nNode)
		{
			mPush(nNode->cData);
			nNode = nNode->next;
		}
		delete nNode;
		nNode = nullptr;
	}

	int mSize() const;
	int mPush(const char*);
	const char* mFirst() const;
	const char* mNext() const;
	const char* mPop();
	void mShowList() const;
	void mReset();
	static TList GetReverseList(TList);
};