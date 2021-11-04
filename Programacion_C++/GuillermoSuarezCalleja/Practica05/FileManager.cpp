#include "FileManager.h"
#include<fstream>
#include<iostream>
using namespace std;

void FileManager::mOpenFile(char _cName[], int _mode)
{
	fstream file;
	char* name = _cName;
	if (_mode == 0)
	{
		file.open(name, ios::in); // writte
		if (file.is_open())
		{
			
		}
	}
	else if (_mode == 1)
	{
		file.open(_cName, ios::out); // read
		if (file.is_open())
		{
			printf("Escribiendo..\n");
			file << "Hello\n";
			file << "Second line\n";
			file.close();
		}
	}
	else
	{

	}
}

// void mReadFile(file* _ptrFile)
// {
// 	fstream* ptrFile = reinterpret_cast<fstream*>(&_ptrFile);
// 	printf("READ FILE\n");
// }

// void* mWriteFile(fstream* _ptrFile)
// {
// 
// }

// void mCloseFile(fstream* _file)
// {
// 	_file->close();
// }