#pragma once

namespace FileManager
{
	void* mOpenFile(const char*, const char*);
	unsigned int mReadFile(void*);
	const char* mWriteFile(void*, const char*, unsigned int);
	unsigned int mNumOfStrings(void*, char*);
	unsigned int mSumaNumeros(void*);
	unsigned int* mNumeros(void*);
	void mCloseFile(void*);
}
