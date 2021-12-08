#pragma once

class CStream
{
protected:
	typedef CStream tdCStream;

public:
	CStream();
	virtual ~CStream(); // destructor virtual

	virtual void vmOpen(const char*);
	virtual void vmRead(const char*);
	virtual void vmWrite(const char*);
	virtual void vmClose(const char*);
};