#include<stdio.h>
#include<stdlib.h>

class FileManager
{
	public:
	FileManager() = default;
	void* mOpenFile(FILE*, const char*, int);
	int mReadFile(FILE*, char*&);
	// char* mWriteFile(FILE*, char*);
	void mCloseFile(FILE*);
};