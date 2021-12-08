#include "File.h"
#include <iostream>

CFile::CFile() : tdCStream()
{
	std::cout << "File stream object created.\n";
}

CFile::~CFile()
{
	std::cout << "File stream object deleted.\n";
}

void CFile::vmOpen(const char* _cName)
{
	tdCStream::vmOpen(_cName);
	std::cout << "[FILE CLASS] - File " << _cName << " opened.\n";
}

void CFile::vmRead(const char* _cName)
{
	tdCStream::vmRead(_cName);
	std::cout << "[FILE CLASS] - File" << _cName << " in " << "[READ] mode.\n";
}

void CFile::vmWrite(const char* _cName)
{
	tdCStream::vmWrite(_cName);
	std::cout << "[FILE CLASS] - File" << _cName << " in " << "[WRITE] mode.\n";
}

void CFile::vmClose(const char* _cName)
{
	tdCStream::vmClose(_cName);
	std::cout << "[FILE CLASS] - File " << _cName << " closed.\n";
}