#include "Stream.h"
#include <iostream>

CStream::CStream()
{
	std::cout << "Stream object created.\n";
}

CStream::~CStream()
{
	std::cout << "Stream object deleted.\n";
}

void CStream::vmOpen(const char* _cName)
{
	std::cout << "[STREAM CLASS] - File " << _cName << " opened.\n";
}

void CStream::vmRead(const char* _cName)
{
	std::cout << "[STREAM CLASS] - File" << _cName << " in " << "[READ] mode.\n";
}

void CStream::vmWrite(const char* _cName)
{
	std::cout << "[STREAM CLASS] - File" << _cName << " in " << "[WRITE] mode.\n";
}

void CStream::vmClose(const char* _cName)
{
	std::cout << "[STREAM CLASS] - File " << _cName << " closed.\n";
}