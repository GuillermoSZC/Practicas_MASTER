#include "Com.h"
#include <iostream>

CCom::CCom() : tdCStream()
{
	std::cout << "Com stream object created.\n";
}

CCom::~CCom()
{
	std::cout << "Com stream object deleted.\n";
}

void CCom::vmOpen(const char* _cName)
{
	tdCStream::vmOpen(_cName);
	std::cout << "[COM CLASS] - File " << _cName << " opened.\n";
}

void CCom::vmRead(const char* _cName)
{
	tdCStream::vmRead(_cName);
	std::cout << "[COM CLASS] - File" << _cName << " in " << "[READ] mode.\n";
}

void CCom::vmWrite(const char* _cName)
{
	tdCStream::vmWrite(_cName);
	std::cout << "[COM CLASS] - File" << _cName << " in " << "[WRITE] mode.\n";
}

void CCom::vmClose(const char* _cName)
{
	tdCStream::vmClose(_cName);
	std::cout << "[COM CLASS] - File " << _cName << " closed.\n";
}