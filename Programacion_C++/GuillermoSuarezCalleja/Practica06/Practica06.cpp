#include <iostream>
#include "FileManager.h"

// PREGUNTAS

int main()
{
	char cBuffer[100];
	char cText[]("Hello world, this is an example file..");
	unsigned int iSize = sizeof(cText) / sizeof(cText[0]);
	const char* cfName("Practica6.txt");
	void* vFile(nullptr);
	bool bVal(true);
	int iOpt(INT_MIN);
	char* cAux(nullptr);
	char cadena[]("Hello");

	do
	{
		std::cout << "What would you like to do?\n"
			"0. Read\n"
			"1. Write\n"
			"2. Count Strings\n" << std::endl;
		std::cin >> iOpt;
		if (iOpt == 0 || iOpt == 1 || iOpt == 2)
		{
			bVal = false;
		}
	} while (bVal);

	switch (iOpt)
	{
	case 0:
		vFile = mOpenFile(cfName, "r");
		std::cout << "Number of characters read: " << mReadFile(vFile, cBuffer, cAux) << std::endl;
		delete cAux;
		cAux = nullptr;
		break;
	case 1:
		vFile = mOpenFile(cfName, "w");
		std::cout << "Characters that was written: " << mWriteFile(vFile, cText, iSize) << std::endl;
		break;
	case 2:
		vFile = mOpenFile(cfName, "r");
		std::cout << "Number of '" << cadena << "'  read: " << mNumOfStrings(vFile, cadena, cAux) << std::endl;
		break;
	}

	return 0;
}

void* mOpenFile(const char* _cName, const char* _cMode)
{
	FILE* file;
	fopen_s(&file, _cName, _cMode);

	return file;
}



unsigned int mReadFile(void* _vFile, char* _cBuffer, char*& _cAux)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	unsigned int uiNumChars(0);
	unsigned int uiNum(0);

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	_cBuffer = new char[uiNum];
	_cAux = _cBuffer;

	uiNumChars = fread(_cBuffer, 1, uiNum - 1, file);
	*(_cBuffer + uiNumChars) = '\0'; 

	//std::cout << "Buffer read: " << _cAux << std::endl;

	mCloseFile(_vFile);

	return uiNumChars;
}

const char* mWriteFile(void* _vFile, const char* _cBuffer, unsigned int _uiSize)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	
	fwrite(_cBuffer, 1, _uiSize, file);
	mCloseFile(_vFile);

	return _cBuffer;
}

unsigned int mNumOfStrings(void* _vFile, char* _cadena, char*& _cAux)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	char* buffer;
	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	unsigned int iSuma(0);
	unsigned int iAux(0);
	unsigned int iSizeCad = strlen(_cadena);
	bool val = true;

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);

	buffer = new char[uiNum];
	_cAux = buffer;

	uiNumChars = fread(buffer, 1, uiNum, file);
	*(buffer + uiNumChars) = '\0';

	for (int i = 0; *(buffer + i) != '\0'; ++i)
	{
		if (*(buffer + i) != ' ' && *(buffer + i) != '\n')
		{
			if (*(buffer + i) == *(_cadena + iAux))
			{
				++iAux;
				if (iAux == iSizeCad)
				{
					if (
						(*(buffer + i + 1) == ' ' || *(buffer + i + 1) == ','
							|| *(buffer + i + 1) == '.' || *(buffer + i + 1) == '\n'
							|| *(buffer + i + 1) == '\0')
						&&
						(*(buffer + i - iSizeCad) == ' '
							|| *(buffer + i - iSizeCad) == ',' || *(buffer + i - iSizeCad) == '.'
							|| *(buffer + i - iSizeCad) == '\n'))
					{
						++iSuma;
						iAux = 0;
						// 							std::cout << "principio 1: " << *(buffer + i - iSizeCad) << std::endl;
						// 							std::cout << "posicion: " << i << std::endl;
					}
					else
					{
						iAux = 0;
					}
				}
			}
		}
	}

	for (unsigned int i = 0; i < iSizeCad; ++i)
	{
		if (*(buffer + i) != *(_cadena + i))
		{
			val = false;
		}
	}
	// std::cout << "FINAL: '" << *(buffer + iSizeCad) << "'" << std::endl;
	if (*(buffer + iSizeCad) != ' ' && *(buffer + iSizeCad) != ','
		&& *(buffer + iSizeCad) != '.')
	{
		val = false;
	}

	if (val)
	{
		++iSuma;
	}

	mCloseFile(_vFile);

	return iSuma;
}

void mCloseFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	// std::cout << "File closed." << std::endl;

	fclose(file);
}