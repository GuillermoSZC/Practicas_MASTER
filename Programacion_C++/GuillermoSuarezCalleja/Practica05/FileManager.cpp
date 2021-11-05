// #pragma once
#include "FileManager.h"

void* FileManager::mOpenFile(const char* _cName, int _mode)
{
	FILE* file = nullptr;
	void* vFile_ = reinterpret_cast<void*>(file);

	if (_mode == 0)
	{
		fopen_s(&file, _cName, "r");
		printf("File opened to read.\n");
		if (!file)
		{
			printf("Error opening file.\n");
		}
		mCloseFile(file);
	}
	else if (_mode == 1)
	{
		fopen_s(&file, _cName, "a");
		printf("File opened to append.\n");
		if (!file)
		{
			printf("Error opening file.\n");
		}
	}
	else
	{

	}
	
	return vFile_;
}

void FileManager::mReadFile(FILE* _file)
{

}

char* FileManager::mWriteFile(FILE* _file, char* _buffer)
{

}

void FileManager::mCloseFile(FILE* _file)
{
	fclose(_file);
	printf("File closed.\n");
}