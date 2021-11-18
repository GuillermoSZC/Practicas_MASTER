#include"TList.h"
#include"FileManager.h"
#include<iostream>

int TList::mPush(TList*& list, const char* cValue)
{
	TList* nNode = new TList();
	nNode->cData = cValue;

	TList* aux1 = list;
	TList* aux2 = nullptr;

	while ((aux1 != nullptr))
	{
		aux2 = aux1;
		aux1 = aux1->next;
	}

	if (list == aux1)
	{
		list = nNode;
	}
	else
	{
		aux2->next = nNode;
	}
	nNode->next = aux1;
	list->iSize++;

	return list->iSize;
}

const char* TList::mFirst(TList*& head)
{
	return head->cData;
}

const char* TList::mNext(TList*& head)
{
	TList* tmp = head;
	tmp = head->next;

	return tmp->cData;
}

const char* TList::mPop(TList*& head)
{
	const char* cString = nullptr;
	if (head)
	{
		cString = head->cData;
		TList* temp = head;
		head = head->next;
		delete temp;
	}

	return cString;
}
//-------------------------------------------------------------------------------------------------------------------------------------
//@TODO:
TList* TList::mPushNumsOfFile(TList*& head)
{
	void* _vFile = FileManager::mOpenFile("FileManager.txt", "r");
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	char* cBuffer;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	cBuffer = new char[uiNum];

	uiNumChars = fread(cBuffer, 1, uiNum - 1, file);
	*(cBuffer + uiNumChars) = '\0';

	unsigned int uiSize = strlen(cBuffer);

	for (unsigned int i = 0; i < uiSize; ++i)
	{
		if (*(cBuffer + i) != ' ')
		{
			std::cout << *(cBuffer + i);
		}
	}

	/*TList* nNode = new TList();
	TList* aux1 = nullptr;
	TList* aux2 = nullptr;

	std::cout << "Size Array: " << iSize << std::endl;

	for (unsigned int i = 0; i < iSize; ++i)
	{
		nNode->cData = ...;

		aux1 = head;
		aux2 = nullptr;

		while ((aux1 != nullptr))
		{
			aux2 = aux1;
			aux1 = aux1->next;
		}

		if (head == aux1)
		{
			head = nNode;
		}
		else
		{
			aux2->next = nNode;
		}
		nNode->next = aux1;
		head->iSize++;
	}*/

	delete[] cBuffer;
	cBuffer = nullptr;
	FileManager::mCloseFile(_vFile);
	return head;
}

void TList::mReset(TList*& head)
{
	TList* tmp = nullptr;
	while (head)
	{
		tmp = head;
		std::cout << "Element " << head->cData << " erased.\n";
		head = head->next;
		delete tmp;
	}
}