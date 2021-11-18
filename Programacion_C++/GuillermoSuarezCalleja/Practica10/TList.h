#pragma once

class  TList
{
private:
	const char* cData = nullptr;
	int iSize = 0;
	TList* next = nullptr;
public:
	TList() {};

	int mPush(TList*&, const char*);
	const char* mFirst(TList*&);
	const char* mNext(TList*&);
	const char* mPop(TList*&);
	void mReset(TList*&);
	TList* mPushNumsOfFile(TList*&);
};