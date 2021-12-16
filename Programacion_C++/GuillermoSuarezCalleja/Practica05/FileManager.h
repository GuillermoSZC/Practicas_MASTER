#pragma once

// El ejercicio 5 se puede hacer con una clase o struct, pero he dejado el namespace que se crea para la practica 7
namespace FileManager
{
	void* mOpenFile(const char*, const char*);
	unsigned int mReadFile(void*, char*, char*&);
	const char* mWriteFile(void*, const char*, unsigned int);
	void mCloseFile(void*);
}

/*class FileManager
{
public:
	FileManager();
	~FileManager();

	void* mOpenFile(const char*, const char*);
	unsigned int mReadFile(void*, char*, char*&);
	const char* mWriteFile(void*, const char*, unsigned int);
	void mCloseFile(void*);

};*/
