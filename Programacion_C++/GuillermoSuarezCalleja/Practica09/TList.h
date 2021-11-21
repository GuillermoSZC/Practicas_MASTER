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

public:
	TList()
	{
		iSize = 0;
		head = nullptr;
		tail = nullptr;
	};

	int mSize();
	int mPush(const char*);
	const char* mFirst();
	const char* mNext();
	const char* mPop();
	void mShowList();
	void mReset();
};