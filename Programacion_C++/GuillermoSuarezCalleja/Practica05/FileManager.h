#include<stdio.h>
#include<stdlib.h>

class FileManager
{
	public:
	FileManager() = default;
	void* mOpenFile(const char*, int);
	void mReadFile(FILE*);
	char* mWriteFile(FILE*, char*);
	void mCloseFile(FILE*);
};