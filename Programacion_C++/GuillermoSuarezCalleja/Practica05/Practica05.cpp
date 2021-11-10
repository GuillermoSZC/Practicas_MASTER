#include <iostream>
#include "FileManager.h"

int main() 
{
	char cBuffer[3];
	char cText[] = "1,2,3,4,5";

	const char* cfName("example.txt");
	void* vFile(nullptr);

	vFile = mOpenFile(cfName, "r");
	std::cout << "Number of chars read: " << mReadFile(vFile, cBuffer) << std::endl;
	mCloseFile(vFile);

	vFile = mOpenFile(cfName, "w");
	std::cout << "Chars that has written: " << mWriteFile(vFile, cText, 1) << std::endl;
	mCloseFile(vFile);

	return 0;
}

void* mOpenFile(const char* _cName, const char* _cMode)
{
	FILE* file;
	fopen_s(&file, _cName, _cMode);

	return file;
}

unsigned int mReadFile(void* _vFile, char* _cBuffer)
{
	unsigned int uiNum(0);
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	fseek(file, 0, SEEK_END);
	uiNum = ftell(file);
	rewind(file);

	_cBuffer = new char[uiNum];

	unsigned int uiNumChars(0);
	uiNumChars = fread(_cBuffer, 1, uiNum, file);
	
	return uiNumChars;
}

const char* mWriteFile(void* _vFile, const char* _cBuffer, unsigned int _uiNum)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	
	fwrite(_cBuffer, 1, _uiNum, file);

	return _cBuffer;
}

void mCloseFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));

	fclose(file);
}