#pragma once
#include "Stream.h"

class CTcp : public CStream
{
public:
	CTcp();
	virtual ~CTcp() override;

	virtual void vmOpen(const char*) override;
	virtual void vmRead(const char*) override;
	virtual void vmWrite(const char*) override;
	virtual void vmClose(const char*) override;
};