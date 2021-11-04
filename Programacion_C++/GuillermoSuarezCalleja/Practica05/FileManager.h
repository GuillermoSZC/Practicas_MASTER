#pragma once
#ifndef FileManager_h
#define FileManager_h

typedef fstream file;
class FileManager
{
	public:
	FileManager();
	void mOpenFile(char[], int);
	void mReadFile(file*);
	void mWriteFile(file*);
	void mCloseFile(file*);
};
#endif // FileManager.h