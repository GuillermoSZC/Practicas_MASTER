#include <iostream>
#include "FileManager.h"
// PREGUNTAS
/*
Mejor meter el closeFIle() en los metodos o llamarlos en el main cada 
vez que llamemos una funcion que abra un archivo?
*/
int main() 
{
	char cBuffer[100];
	char cText[]("Hello world, this is an example file..");
	unsigned int iSize = sizeof(cText) / sizeof(cText[0]);
	const char* cfName("Practica5.txt");
	void* vFile(nullptr);
	bool bVal(true);
	int iOpt(INT_MIN);
	char* cAux(nullptr);

	do 
	{
		std::cout << "What would you like to do? 0 - 1" << std::endl;
		std::cin >> iOpt;
		if (iOpt == 0 || iOpt == 1)
		{
			bVal = false;
		}
	} while (bVal);

	if (iOpt == 0)
	{
		vFile = FileManager::mOpenFile(cfName, "r");
		std::cout << "Number of chars read: " << FileManager::mReadFile(vFile, cBuffer, cAux) << std::endl;
		delete cAux;
		cAux = nullptr;
	}
	else if (iOpt == 1)
	{
		vFile = FileManager::mOpenFile(cfName, "w");
		std::cout << "Characters that was written: " << FileManager::mWriteFile(vFile, cText, iSize) << std::endl;
	}

	return 0;
}

void* FileManager::mOpenFile(const char* _cName, const char* _cMode)
{
	FILE* file;
	fopen_s(&file, _cName, _cMode);

	return file;
}

unsigned int FileManager::mReadFile(void* _vFile, char* _cBuffer, char*& _cAux)
{
	unsigned int uiNumChars(0);
	unsigned int uiNum(0);
	
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file) + 1;
	rewind(file);
	_cBuffer = new char[uiNum];
	_cAux = _cBuffer;

	uiNumChars = fread(_cBuffer, 1, uiNum - 1, file);
	// *(_cBuffer + uiNumChars) = '\0'; 

	// std::cout << "Buffer read: " << _cAux << std::endl;

	mCloseFile(_vFile);

	return uiNumChars;
}

const char* FileManager::mWriteFile(void* _vFile, const char* _cBuffer, unsigned int _uiSize)
{
	
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	
	fwrite(_cBuffer, 1, _uiSize, file);
	mCloseFile(_vFile);

	return _cBuffer;
}

void FileManager::mCloseFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	// std::cout << "File closed." << std::endl;

	fclose(file);
}