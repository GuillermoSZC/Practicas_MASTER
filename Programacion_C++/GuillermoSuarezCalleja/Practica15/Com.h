#pragma once
#include "Stream.h"

class CCom : public CStream
{
public:
	CCom();
	virtual ~CCom() override;

	virtual void vmOpen(const char*) override;
	virtual void vmRead(const char*) override;
	virtual void vmWrite(const char*) override;
	virtual void vmClose(const char*) override;
};