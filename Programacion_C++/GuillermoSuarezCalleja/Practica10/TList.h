#pragma once

class  TList
{
private:
	struct Nodo
	{
		const char* cData;
		int id;
		Nodo* next;
		Nodo* prev;

		Nodo() = default;
		Nodo(const char* value)
		{
			id = 0;
			cData = value;
			next = nullptr;
			prev = nullptr;
		}
	}/**head, *tail*/;
	
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
	TList* mPushNumsOfFile(const char*, char*&);
	void mShowList();
	void mReset();
};