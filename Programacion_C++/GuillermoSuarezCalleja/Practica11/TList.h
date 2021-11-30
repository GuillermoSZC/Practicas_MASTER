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
		if (!list->head)
		{
			head = nullptr;
		}
		else
		{
			mPush(list->head->cData);
			nNode = list->head->next;
		}

		while (nNode)
		{
			mPush(nNode->cData);
			nNode = nNode->next;
		}
		delete nNode;
		nNode = nullptr;
	}

	int mSize();
	int mPush(const char*);
	const char* mFirst();
	const char* mNext();
	const char* mPop();
	void mShowList();
	void mReset();
	static TList GetReverseList(TList);
};