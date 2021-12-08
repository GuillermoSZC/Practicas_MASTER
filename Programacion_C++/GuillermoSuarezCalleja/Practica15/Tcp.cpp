#include "Tcp.h"
#include <iostream>

CTcp::CTcp() : tdCStream()
{
	std::cout << "Tcp stream object created.\n";
}

CTcp::~CTcp()
{
	std::cout << "Tcp stream object deleted.\n";
}

void CTcp::vmOpen(const char* _cName)
{
	tdCStream::vmOpen(_cName);
	std::cout << "[TCP CLASS] - File " << _cName << " opened.\n";
}

void CTcp::vmRead(const char* _cName)
{
	tdCStream::vmRead(_cName);
	std::cout << "[TCP CLASS] - File" << _cName << " in " << "[READ] mode.\n";
}

void CTcp::vmWrite(const char* _cName)
{
	tdCStream::vmWrite(_cName);
	std::cout << "[TCP CLASS] - File" << _cName << " in " << "[WRITE] mode.\n";
}

void CTcp::vmClose(const char* _cName)
{
	tdCStream::vmClose(_cName);
	std::cout << "[TCP CLASS] - File " << _cName << " closed.\n";
}