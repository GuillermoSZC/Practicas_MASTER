#include"TList.h"
#include"FileManager.h"
#include<iostream>
#include<string>

int TList::mPush(const char* cValue)
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

const char* TList::mFirst()
{
	return head->cData;
}

const char* TList::mNext()
{
	TList::Nodo* tmp = head;
	tmp = head->next;

	return tmp->cData;
}

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
}

void TList::mShowList()
{
	TList aux;
	aux.head = head;

	while (aux.head != NULL)
	{
		std::cout << "Element " << aux.head->id << ": " << aux.head->cData << std::endl;
		aux.head = aux.head->next;
	}
}

TList* TList::mPushNumsOfFile(const char* _cName, char *& _aux)
{
	void* _vFile = FileManager::mOpenFile(_cName, "r");
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	TList* node = new TList();

	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	unsigned int uiValComma(1);
	char* cBuffer;
	unsigned int uiSize(0);
	std::string sCad = "";
	bool bSemaph = false;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	cBuffer = new char[uiNum];

	uiNumChars = fread(cBuffer, 1, uiNum - 1, file);
	*(cBuffer + uiNumChars) = '\0';

	// unsigned int uiSize = strlen(cBuffer);

	for (unsigned int i = 0; i < uiNumChars + 1; ++i)
	{
		if ((*(cBuffer + i) >= 48 && *(cBuffer + i) <= 57)) // Numeros del 0 al 9 en ASCII
		{
			bSemaph = true;
			sCad += *(cBuffer + i);
			uiValComma++;
		}
		else
		{
			if (bSemaph)
			{
				if (*(cBuffer + i - uiValComma) == ',' || *(cBuffer + i) == ',')
				{
					uiSize = strlen(sCad.c_str());
					_aux = new char[uiSize + 1]; 
					*(_aux + uiSize) = '\0';
					
					for (unsigned int j = 0; j < uiSize; ++j)
					{
						*(_aux + j) = sCad[j];
					}
					// std::cout << _aux << std::endl;
					node->mPush(_aux);
					sCad = "";
					uiValComma = 1;
					bSemaph = false;
				}
				else
				{
					sCad = "";
				}
			}
		}	
	}

	delete[] cBuffer;
	cBuffer = nullptr;
	FileManager::mCloseFile(_vFile);

	return node;
}

void TList::mReset()
{
	TList::Nodo* tmp = nullptr;
	while (head)
	{
		tmp = head;
		std::cout << "Element " << head->id << ": " << head->cData << " erased.\n";
		head = head->next;
		delete tmp;
	}
}