#pragma once
#include "Stream.h"

class CFile : public CStream
{
public:
	CFile();
	~CFile() override;

	virtual void vmOpen(const char*) override;
	virtual void vmRead(const char*) override;
	virtual void vmWrite(const char*) override;
	virtual void vmClose(const char*) override;
};