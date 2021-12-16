#include"FileManager.h"
#include <iostream>

FileManager::FileManager()
{
	printf("Object FileManager created.\n");
}

FileManager::~FileManager()
{
	printf("Object FileManager deleted.\n");
}

void* FileManager::mOpenFile(const char* _cName, const char* _cMode)
{
	FILE* file;
	fopen_s(&file, _cName, _cMode);

	return file;
} // metodo para abrir el fichero

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
} // metodo que devuelve el numero de caracteres leidos del fichero

const char* FileManager::mWriteFile(void* _vFile, const char* _cBuffer, unsigned int _uiSize)
{

	FILE* file(reinterpret_cast<FILE*>(_vFile));

	fwrite(_cBuffer, 1, _uiSize, file);
	mCloseFile(_vFile);

	return _cBuffer;
} // metodo para escribir en el fichero, devuelve la cadena escrita

void FileManager::mCloseFile(void* _vFile)
{
	FILE* file(reinterpret_cast<FILE*>(_vFile));
	// std::cout << "File closed." << std::endl;

	fclose(file);
} // metodo para cerrar el fichero