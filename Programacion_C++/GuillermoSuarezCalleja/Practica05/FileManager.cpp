// #pragma once
#include "FileManager.h"

void* FileManager::mOpenFile(FILE*_file, const char* _cName, int _mode)
{
	void* vFile_ = reinterpret_cast<void*>(_file);

	if (_mode == 0)
	{
		fopen_s(&_file, _cName, "r");
		printf("File opened to read.\n");
		if (!_file)
		{
			printf("Error opening file.\n");
		}
	}
	else if (_mode == 1)
	{
		fopen_s(&_file, _cName, "a");
		printf("File opened to append.\n");
		if (!_file)
		{
			printf("Error opening file.\n");
		}
	}
	
	return vFile_;
}

int FileManager::mReadFile(FILE* _file, char*& buffer)
{
	int suma(0), num(0);
	size_t resultado;
	while (!feof(_file)) 
	{
		resultado = fread(&num, sizeof(int), 1, _file);
		if (resultado != 1)
		{
			break;
		}
		suma += num;
	}
	return suma;
}
/*

char* FileManager::mWriteFile(FILE* _file, char* _buffer)
{

}
*/

void FileManager::mCloseFile(FILE* _file)
{
	fclose(_file);
	printf("File closed.\n");
}