#include"FileManager.h"
#include <iostream>

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