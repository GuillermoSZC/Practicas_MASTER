#pragma once

class Enemy
{
public:
	virtual const char* vmGetType() const = 0;
	virtual const char* vmGetName() const = 0;
	virtual void vmGetStats() const = 0;
};
