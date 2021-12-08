#pragma once
#include "Enemy.h"

class  TList
{
private:
	struct Nodo 
	{
		Enemy* cData;
		Nodo* next;
		Nodo* prev;
		int id;

		Nodo(Enemy* value) 
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

	int mSize();
	int mPush(Enemy*);
	Enemy* mFirst() const;
	Enemy* mNext();
	Enemy* mPop();
	void mShowList();
	void mReset();
};